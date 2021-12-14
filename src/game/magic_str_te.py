"""
---------Text Engine String Source File----------
To make a string, simply create a variable and make a list of strings. This variable
will be turned into byte code with a tool during the make process.
To put externs and headers in your file for references, you must place them in variables
called externs, and headers, which are also iterable strings.
externs and headers must be have these exact names or will be treated as TE strings.
non iterables are ignored. If you have a tuple with a single item, put a comma after it
or else it will be ignored
"""
#This is externs delcared in this file
externs = ("extern const Gfx star_seg3_dl_0302B870[];",)
#These are header files included in this file. Use single quotes so double quotes are delimited for filename
headers = (r'#include "src/game/segment2.h"',r'#include "include/sm64.h"',r'#include "src/game/magic.h"',r'#include "src/game/area.h"')

magic_spells_init = ['[CallOnce(1,"TE_set_flag",2,["&gMagicHUDRequest","HUD_OPEN"])]\
[StartTransition(8,255,0,0)][AutoNextBox()]\
[MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)]\n\
[BoxTransition(0,0,-72,0)]\
[SetScissor(14,80,230,230)]\
[ShadedBGBox(14,80,158,215,0,0,0,0x96)]\
[CallLoop(4,"TE_get_flag",2,["&gMagicHUDRequest","CASTING_ON_PLAT"])][MatchRtrn(4,1)][Jump("magic_on_plat")][GenericText()]\
[PrintGlyph("magic_d_up")]ITEMS\n\
[PrintGlyph("magic_d_left")]WORLD\n\
[PrintGlyph("magic_d_right")]SPIRIT\n\
[PrintGlyph("magic_d_down")]ENV ',
#[I explicitly do not use btn enums here because these are char arrays and btns are shorts]
'[BtnBranchOpen(0x800)][CallOnce(0,"mario_set_spell",1,["cancel"])][Jump("magic_list_items")][BtnBranchClose()]\
[BtnBranchOpen(0x400)][CallOnce(0,"mario_set_spell",1,["cancel"])][Jump("magic_list_env")][BtnBranchClose()]\
[BtnBranchOpen(0x200)][CallOnce(0,"mario_set_spell",1,["cancel"])][Jump("magic_list_spells")][BtnBranchClose()]\
[BtnBranchOpen(0x100)][CallOnce(0,"mario_set_spell",1,["cancel"])][Jump("magic_list_spirit")][BtnBranchClose()]\
[end]']

magic_on_plat = ['[AutoNextBox()][JumpLink("magic_gen_shadow_fade_io")][AutoNextBox()]cannot use ACTION while\non ENV platform.[SetSpd(1)][Pause(60)][AutoNextBox()][CallOnce(0,"TE_set_state",2,["&gMagicHUDRequest",0])][EndTransition(0,0,0,0)][TimeEndStr(1)][end]']


magic_list_chk_cancel = ['\
[BtnBranchOpen(0x20)][CallLoop(0,"TE_set_flag",2,["&gMagicHUDRequest","CANCEL_HUD"])][BtnBranchClose()]\
[BtnBranchOpen(0x4000)][CallLoop(0,"TE_set_flag",2,["&gMagicHUDRequest","CANCEL_HUD"])][BtnBranchClose()]\
cancel[Pop()]']

magic_list_start_cast = ['[CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","START_CAST"])][Pause(1)][CallLoop(1,"TE_get_flag",2,["&gMagicHUDRequest","CASTING_SEL"])]\
[MatchRtrn(1,0)][not matching, do generic cancel check][JumpLink("magic_list_chk_cancel")][end][MatchRtrn(1,1)][Pop()]']


magic_list_items = ['[AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,90,158,215,0,0,0,0x96)]]\n\
[JumpLink("magic_list_start_cast")]',
#list of all the spells goes here
'[CallLoop(3,"create_magic_list_dialog",2,[0,12])]\
[MatchRtrn(3,0)]item list\nempty[TransAbs(16,160)][JumpLink("magic_list_chk_cancel")][end][GenericText()][TransAbs(16,160)][JumpLink("magic_list_chk_cancel")]\
[MatchRtrn(3,1)][TransAbs(16,212)][CallLoop(0,"list_scroll_y_dialog",0,[])][UsrStr(12)][SetScissor(14,90,174,210)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","magic_pot"])][MatchRtrn(2,1)]magic pot[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","magic_pot2"])][MatchRtrn(2,1)]magic pot[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","magic_pot3"])][MatchRtrn(2,1)]magic pot[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","magic_pot4"])][MatchRtrn(2,1)]magic pot[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","health_pot"])][MatchRtrn(2,1)]health pot[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","health_pot2"])][MatchRtrn(2,1)]health pot[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","health_pot3"])][MatchRtrn(2,1)]health pot[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","health_pot4"])][MatchRtrn(2,1)]health pot[end][GenericText()]',
#end of the spells
'[GenericText()][CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","CAST_ITEM"])][AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][CallOnce(3,"Get_Spell_Sel",1,[0])][ShadedBGBox(14,80,158,215,0,0,0,0x96)]]\n\
[MatchRtrn(3,0)]magic pot used[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,1)]magic pot used[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,2)]magic pot used[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,3)]magic pot used[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,4)]health pot used[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,5)]health pot used[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,6)]health pot used[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,7)]health pot used[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[GenericText()][end]']

magic_list_spells = ['[AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,105,158,215,0,0,0,0x96)]\n\
[JumpLink("magic_list_start_cast")]',
#list of all the spells goes here
'[CallLoop(3,"create_magic_list_dialog",2,[1,13])]\
[MatchRtrn(3,0)]no world\nspells[TransAbs(16,160)][JumpLink("magic_list_chk_cancel")][end][GenericText()][TransAbs(16,160)][JumpLink("magic_list_chk_cancel")]\
[MatchRtrn(3,1)][TransAbs(16,212)][CallLoop(0,"list_scroll_y_dialog",0,[])][UsrStr(13)][SetScissor(14,105,174,210)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","checkpoint"])][MatchRtrn(2,1)]Checkpoint[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","time_freeze"])][MatchRtrn(2,1)]Time Freeze[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","destroy_enemy"])][MatchRtrn(2,1)]Destruction[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","teleport_portal"])][MatchRtrn(2,1)]Teleport[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","spell5"])][MatchRtrn(2,1)]spell5[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","spell6"])][MatchRtrn(2,1)]spell6[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","spell7"])][MatchRtrn(2,1)]spell7[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","spell8"])][MatchRtrn(2,1)]spell8[end][GenericText()]',
#end of the spells
'[GenericText()][CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","CAST_SPELL"])][AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][CallOnce(3,"Get_Spell_Sel",1,[1])][ShadedBGBox(14,80,158,215,0,0,0,0x96)]]\n\
[MatchRtrn(3,0)]Checkpoint Cast[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,1)]Time Freeze[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,2)]Destruction[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,3)]Teleport[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,4)]spell5[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,5)]spell6[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,6)]spell7[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[MatchRtrn(3,7)]spell8[Pause(90)][AutoNextBox()][TimeEndStr(1)]\
[GenericText()][end]']


magic_spirit_list_end = ['[SetSpd(1)][Pause(120)][AutoNextBox()][CallOnce(0,"TE_set_state",2,["&gMagicHUDRequest",0])][TimeEndStr(1)]']

magic_list_spirit = ['[AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,90,158,215,0,0,0,0x96)]\n\
[JumpLink("magic_list_start_cast")]',
#list of all the spells goes here
'[CallLoop(3,"create_magic_list_dialog",2,[2,14])]\
[MatchRtrn(3,0)]no spirit\nspells[TransAbs(16,160)][JumpLink("magic_list_chk_cancel")][end][GenericText()][TransAbs(16,160)][JumpLink("magic_list_chk_cancel")]\
[MatchRtrn(3,1)][TransAbs(16,212)][CallLoop(0,"list_scroll_y_dialog",0,[])][UsrStr(14)][SetScissor(14,90,174,210)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","gigantify"])][MatchRtrn(2,1)]Gigantify[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","hover"])][MatchRtrn(2,1)]Hover[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","stick"])][MatchRtrn(2,1)]Stick[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","test5"])][MatchRtrn(2,1)]ss[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","test4"])][MatchRtrn(2,1)]d[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","test1"])][MatchRtrn(2,1)]spell6[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","test2"])][MatchRtrn(2,1)]spell7[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","test3"])][MatchRtrn(2,1)]spell8[end][GenericText()]',
#end of the spells
'[GenericText()][CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","CAST_SPIRIT"])][AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][CallOnce(3,"Get_Spell_Sel",1,[2])][ShadedBGBox(14,90,194,215,0,0,0,0x96)]]\n\
[MatchRtrn(3,0)]Gigantify[CallOnce(0,"mario_set_spell",1,["gigantify"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,1)]Hover[CallOnce(0,"mario_set_spell",1,["hover"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,2)]Stick[CallOnce(0,"mario_set_spell",1,["stick"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,3)]ss[Jump("magic_spirit_list_end")]\
[MatchRtrn(3,4)]d[Jump("magic_spirit_list_end")]\
[MatchRtrn(3,5)]spell6[Jump("magic_spirit_list_end")]\
[MatchRtrn(3,6)]spell7[Jump("magic_spirit_list_end")]\
[MatchRtrn(3,7)]spell8[Jump("magic_spirit_list_end")]\
[GenericText()][end]']


magic_list_env = ['[AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,118,158,215,0,0,0,0x96)]\n\
[JumpLink("magic_list_start_cast")]',
#list of all the spells goes here
'[CallLoop(3,"create_magic_list_dialog",2,[3,15])]\
[MatchRtrn(3,0)]no env\nspells[TransAbs(16,160)][JumpLink("magic_list_chk_cancel")][end][GenericText()][TransAbs(16,160)][JumpLink("magic_list_chk_cancel")]\
[MatchRtrn(3,1)][TransAbs(16,212)][CallLoop(0,"list_scroll_y_dialog",0,[])][UsrStr(15)][SetScissor(14,118,174,210)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","ice_block"])][MatchRtrn(2,1)]Ice Block[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","hanging_leaf"])][MatchRtrn(2,1)]Hanging Leaf[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","cloud_lob"])][MatchRtrn(2,1)]Floating Cloud[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk4"])][MatchRtrn(2,1)]spell4[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk5"])][MatchRtrn(2,1)]spell5[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk6"])][MatchRtrn(2,1)]spell6[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk7"])][MatchRtrn(2,1)]spell7[end][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk8"])][MatchRtrn(2,1)]spell8[end][GenericText()]',
#end of the spells
'[GenericText()][CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","CAST_ENVIRONMENT"])][AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][CallOnce(3,"Get_Spell_Sel",1,[3])][ShadedBGBox(14,108,194,215,0,0,0,0x96)]]\n\
[MatchRtrn(3,0)]Ice Block[CallOnce(0,"mario_set_spell",1,["ice_block"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,1)]Hanging Leaf[CallOnce(0,"mario_set_spell",1,["hanging_leaf"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,2)]Floating Cloud[CallOnce(0,"mario_set_spell",1,["cloud_lob"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,3)]unk spawn4[CallOnce(0,"mario_set_spell",1,["ice_block"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,4)]unk spawn5[CallOnce(0,"mario_set_spell",1,["ice_block"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,5)]unk spawn6[CallOnce(0,"mario_set_spell",1,["ice_block"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,6)]unk spawn7[CallOnce(0,"mario_set_spell",1,["ice_block"])][Jump("magic_spirit_list_end")]\
[MatchRtrn(3,7)]unk spawn8[CallOnce(0,"mario_set_spell",1,["ice_block"])][Jump("magic_spirit_list_end")]\
[GenericText()][end]']


magic_gen_shadow_fade_io = ['[EndTransition(10,0,0,0)][StartTransition(10,0,0,0)][ShadowText(1)][Pop()]']
magic_cannot_place_floor = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]ice block must be placed on floor[TimeEndStr(60)]"]
magic_cannot_place_ceil = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]hanging leaf must be under a ceiling[TimeEndStr(60)]"]
magic_cannot_place_oob = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]floating cloud cannot be placed out of bounds[TimeEndStr(60)]"]