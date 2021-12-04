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
[PrintGlyph("magic_d_up")]ITEMS\n\
[PrintGlyph("magic_d_left")]WORLD\n\
[PrintGlyph("magic_d_right")]SPIRIT\n\
[PrintGlyph("magic_d_down")]ENV ',
#[I explicitly do not use btn enums here because these are char arrays and btns are shorts]
'[BtnBranchOpen(0x800)][Jump("magic_list_items")][BtnBranchClose()]\
[BtnBranchOpen(0x400)][Jump("magic_list_env")][BtnBranchClose()]\
[BtnBranchOpen(0x200)][Jump("magic_list_spells")][BtnBranchClose()]\
[BtnBranchOpen(0x100)][Jump("magic_list_spirit")][BtnBranchClose()]\
[end]']

magic_list_chk_cancel = ['\
[BtnBranchOpen(0x20)][CallLoop(0,"TE_set_flag",2,["&gMagicHUDRequest","CANCEL_HUD"])][BtnBranchClose()]\
[BtnBranchOpen(0x4000)][CallLoop(0,"TE_set_flag",2,["&gMagicHUDRequest","CANCEL_HUD"])][BtnBranchClose()]\
cancel[Pop()]']

magic_list_start_cast = ['[CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","START_CAST"])][Pause(1)][CallLoop(1,"TE_get_flag",2,["&gMagicHUDRequest","CASTING_SEL"])]\
[MatchRtrn(1,0)][not matching, do generic cancel check][JumpLink("magic_list_chk_cancel")][end][MatchRtrn(1,1)][Pop()]']


magic_list_items = ['[AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,80,158,215,0,0,0,0x96)]]\n\
[JumpLink("magic_list_start_cast")]',
#list of all the spells goes here
'[CallLoop(3,"create_magic_list_dialog",2,[0,12])]\
[MatchRtrn(3,0)]item list\nempty[GenericText()][TransAbs(16,160)][JumpLink("magic_list_chk_cancel")]\
[MatchRtrn(3,1)][TransAbs(16,212)][CallLoop(0,"list_scroll_y_dialog",0,[])][UsrStr(12)][SetScissor(14,80,174,210)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","magic_pot"])][MatchRtrn(2,1)]magic pot[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","magic_pot2"])][MatchRtrn(2,1)]magic pot[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","magic_pot3"])][MatchRtrn(2,1)]magic pot[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","magic_pot4"])][MatchRtrn(2,1)]magic pot[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","health_pot"])][MatchRtrn(2,1)]health pot[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","health_pot2"])][MatchRtrn(2,1)]health pot[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","health_pot3"])][MatchRtrn(2,1)]health pot[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","health_pot4"])][MatchRtrn(2,1)]health pot[end][MatchRtrn(2,0)]',
#end of the spells
'[GenericText()][end]']

magic_list_spells = ['[AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,80,158,215,0,0,0,0x96)]\n\
[JumpLink("magic_list_start_cast")]',
#list of all the spells goes here
'[CallLoop(3,"create_magic_list_dialog",2,[1,13])]\
[MatchRtrn(3,0)]no world\nspells[GenericText()][TransAbs(16,160)][JumpLink("magic_list_chk_cancel")]\
[MatchRtrn(3,1)][TransAbs(16,212)][CallLoop(0,"list_scroll_y_dialog",0,[])][UsrStr(13)][SetScissor(14,80,174,210)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","checkpoint"])][MatchRtrn(2,1)]checkpoint[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","time_freeze"])][MatchRtrn(2,1)]time freeze[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","destroy_enemy"])][MatchRtrn(2,1)]destruction[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","teleport_portal"])][MatchRtrn(2,1)]teleport[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","spell5"])][MatchRtrn(2,1)]spell5[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","spell6"])][MatchRtrn(2,1)]spell6[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","spell7"])][MatchRtrn(2,1)]spell7[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","spell8"])][MatchRtrn(2,1)]spell8[end][MatchRtrn(2,0)]',
#end of the spells
'[GenericText()][end]']

magic_list_spirit = ['[AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,80,158,215,0,0,0,0x96)]\n\
[JumpLink("magic_list_start_cast")]',
#list of all the spells goes here
'[CallLoop(3,"create_magic_list_dialog",2,[2,14])]\
[MatchRtrn(3,0)]no spirit\nspells[GenericText()][TransAbs(16,160)][JumpLink("magic_list_chk_cancel")]\
[MatchRtrn(3,1)][TransAbs(16,212)][CallLoop(0,"list_scroll_y_dialog",0,[])][UsrStr(14)][SetScissor(14,80,174,210)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","super_strength"])][MatchRtrn(2,1)]strength[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","floaty_jumps"])][MatchRtrn(2,1)]float[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","wall_stick"])][MatchRtrn(2,1)]stick[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","water_walk"])][MatchRtrn(2,1)]jesus[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","immunity"])][MatchRtrn(2,1)]invincible[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","test1"])][MatchRtrn(2,1)]spell6[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","test2"])][MatchRtrn(2,1)]spell7[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","test3"])][MatchRtrn(2,1)]spell8[end][MatchRtrn(2,0)]',
#end of the spells
'[GenericText()][end]']

magic_list_env = ['[AutoNextBox()][MosaicBGBox(12,82,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,80,158,215,0,0,0,0x96)]\n\
[JumpLink("magic_list_start_cast")]',
#list of all the spells goes here
'[CallLoop(3,"create_magic_list_dialog",2,[3,15])]\
[MatchRtrn(3,0)]no env\nspells[GenericText()][TransAbs(16,160)][JumpLink("magic_list_chk_cancel")]\
[MatchRtrn(3,1)][TransAbs(16,212)][CallLoop(0,"list_scroll_y_dialog",0,[])][UsrStr(15)][SetScissor(14,80,174,210)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","ice_block"])][MatchRtrn(2,1)]ice block[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","rising_leaf"])][MatchRtrn(2,1)]rising leaf[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","cloud_lob"])][MatchRtrn(2,1)]cloud lob[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk4"])][MatchRtrn(2,1)]spell4[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk5"])][MatchRtrn(2,1)]spell5[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk6"])][MatchRtrn(2,1)]spell6[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk7"])][MatchRtrn(2,1)]spell7[end][MatchRtrn(2,0)]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","unk8"])][MatchRtrn(2,1)]spell8[end][MatchRtrn(2,0)]',
#end of the spells
'[GenericText()][end]']
