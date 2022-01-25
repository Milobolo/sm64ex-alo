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
externs = ("extern const Gfx star_seg3_dl_0302B870[];","extern struct Object *gReturn;","extern s8 sSelectedFileNum;")
#These are header files included in this file. Use single quotes so double quotes are delimited for filename
headers = (r'#include "src/game/segment2.h"',r'#include "include/sm64.h"',r'#include "src/game/magic.h"',r'#include "src/game/area.h"',r'#include "src/game/save_file.h"',r'#include "src/menu/file_select.h"')

magic_file_select = ["[SetRtrn(0)][SetEnv(0,0,0,255)][ScaleText(2.0,2.0)][TransOffs(40,0)]SHINING STARS 4\n[TransOffs(-50,0)]ELEPHANT STAR ADVENTURE\n[ScaleText(1.0,1.0)]\
[TransOffs(10,0)][DialogOptions(3)]\
CHOOSE FILE[end]\
ERASE FILE[end]\
COPY FILE[end]\
CREDITS[end]\
[SetEnv(0,0,0,255)][DialogResponse(3)][Jump('ss4_credits')]\
[DialogResponse(2)][StartDialogBracket(1)][CallOnce(0,'TE_set_state',2,['&Op_Type',3])][ScaleText(2.0,2.0)][TransOffs(30,0)]COPY FROM FILE\n[ScaleText(1.0,1.0)][TransOffs(-30,0)][DialogOptions(2)]\
ELEPHANT A[CallLoop(1,'TE_print_star_cnt',2,[0,0])] [UsrStr(0)] STARS[end]\
ELEPHANT B[CallLoop(1,'TE_print_star_cnt',2,[1,1])] [UsrStr(1)] STARS[end]\
BACK[end]\
[DialogResponse(0)][CallOnce(0,'TE_set_state',2,['&copy',0])]\
[DialogResponse(1)][CallOnce(0,'TE_set_state',2,['&copy',1])]\
[DialogResponse(2)][ClearBuffer()][GotoRtrn(0)][end]\
[GenericText()][SetEnv(0,0,0,255)][StartGenBracket(0)][EndDialogBracket(1)]\
\
[copy files is above, choosing files below]\
\
[DialogResponse(0)][CallOnce(0,'TE_set_state',2,['&Op_Type',1])]\
[DialogResponse(1)][CallOnce(0,'TE_set_state',2,['&Op_Type',2])]\
[EndGenBracket(0)][GenericText()][SetEnv(0,0,0,255)][ScaleText(2.0,2.0)][TransOffs(30,0)]CHOOSE FILE\n[ScaleText(1.0,1.0)][TransOffs(-30,0)][DialogOptions(2)]\
ELEPHANT A[CallLoop(1,'TE_print_star_cnt',2,[0,0])] [UsrStr(0)] STARS[end]\
ELEPHANT B[CallLoop(1,'TE_print_star_cnt',2,[1,1])] [UsrStr(1)] STARS[end]\
BACK[end]\
[DialogResponse(0)][StartDialogBracket(1)][CallOnce(0,'FS_do_operation',1,[0])][EndDialogBracket(1)]\
[DialogResponse(1)][StartDialogBracket(1)][CallOnce(0,'FS_do_operation',1,[1])][EndDialogBracket(1)]\
[DialogResponse(2)][ClearBuffer()][GotoRtrn(0)][end]\
[GenericText()][CallOnce(3,'TE_get_state',1,['&Op_Type'])][MatchRtrn(3,1)][TimeEndStr(1)][end][GenericText()][ClearBuffer()][GotoRtrn(0)][end]\
"]

ss4_credits = ["[SetEnv(0,0,0,255)][TransOffs(40,0)]\
Original levels - sm64pie\n\n\
Remade levels - scuttlebug_raiser\n\n\
music ports - scuttlebug_raiser\n\n\
tools used:\n\
fast64, decomp\
[AbtnNextBox()][GotoRtrn(0)]"]

magic_spells_init = ['[CallOnce(1,"TE_set_flag",2,["&gMagicHUDRequest","HUD_OPEN | HUD_MAIN"])]\
[StartTransition(8,255,0,0)][AutoNextBox()]\
[MosaicBGBox(24,94,214,234,"magic_action_menu",2,1)]\n\
[BoxTransition(0,0,-60,0)]\
[SetScissor(14,110,230,230)]\
[ShadedBGBox(14,110,170,215,0,0,0,0x96)]\
[CallLoop(3,"mario_can_cast",0,[])][MatchRtrn(3,0)][Jump("no_magic_unlock")][GenericText()][Pad()]\
[CallLoop(4,"TE_get_flag",2,["&gMagicHUDRequest","CASTING_ON_PLAT"])][MatchRtrn(4,1)][Jump("magic_on_plat")][GenericText()]\
[CallLoop(4,"TE_get_flag",2,["&gMagicHUDRequest","CAST_WAIT"])][MatchRtrn(4,1)][Jump("magic_wait")][GenericText()][Pad()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","sp_return"])][MatchRtrn(2,1)][PrintGlyph("magic_d_left")]RETURN\n[GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","gigantify"])][MatchRtrn(2,1)][PrintGlyph("magic_d_right")]GIGANTIFY\n[GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","ice_block"])][MatchRtrn(2,1)][PrintGlyph("magic_d_down")]ICE BLOCK ',
#[I explicitly do not use btn enums here because these are char arrays and btns are shorts]
'[GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","ice_block"])][MatchRtrn(2,1)][BtnBranchOpen(0x400)][CallOnce(0,"mario_set_spell",1,["ACTION_NULL"])][Jump("magic_list_env")][BtnBranchClose()][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","sp_return"])][MatchRtrn(2,1)][BtnBranchOpen(0x200)][CallOnce(0,"mario_set_spell",1,["ACTION_NULL"])][Jump("magic_list_spells")][BtnBranchClose()][GenericText()]\
[CallLoop(2,"mario_has_spell_TE",2,["&gCurrSaveFileNum","gigantify"])][MatchRtrn(2,1)][BtnBranchOpen(0x100)][CallOnce(0,"mario_set_spell",1,["ACTION_NULL"])][Jump("magic_list_spirit")][BtnBranchClose()]\
[GenericText()][end]']

magic_wait = ["cannot\ncast while\nmoving[end]"]
no_magic_unlock = ['no magic\nunlocked[Jump("magic_spirit_list_end")]']

magic_spells_spell_init = ['[CallOnce(1,"TE_set_flag",2,["&gMagicHUDRequest","HUD_OPEN | HUD_MAIN"])]\
[StartTransition(8,255,0,0)][AutoNextBox()]\
[MosaicBGBox(24,94,214,234,"magic_action_menu",2,1)]\n\
[BoxTransition(0,0,-72,0)]\
[SetScissor(14,110,230,230)]\
[ShadedBGBox(14,110,158,215,0,0,0,0x96)]\
[CallLoop(4,"TE_get_flag",2,["&gMagicHUDRequest","CAST_WAIT"])][MatchRtrn(4,1)][Jump("magic_wait")][GenericText()]\
[PrintGlyph("magic_d_left")]SPELL',
#[I explicitly do not use btn enums here because these are char arrays and btns are shorts]
'[BtnBranchOpen(0x200)][CallOnce(0,"mario_set_spell",1,["ACTION_NULL"])][Jump("magic_list_spells")][BtnBranchClose()]\
[end]']

magic_spells_env_init = ['[CallOnce(1,"TE_set_flag",2,["&gMagicHUDRequest","HUD_OPEN | HUD_MAIN"])]\
[StartTransition(8,255,0,0)][AutoNextBox()]\
[MosaicBGBox(24,94,214,234,"magic_action_menu",2,1)]\n\
[BoxTransition(0,0,-72,0)]\
[SetScissor(14,110,230,230)]\
[ShadedBGBox(14,110,158,215,0,0,0,0x96)]\
[CallLoop(4,"TE_get_flag",2,["&gMagicHUDRequest","CAST_WAIT"])][MatchRtrn(4,1)][Jump("magic_wait")][GenericText()]\
[PrintGlyph("magic_d_down")]ENV ',
#[I explicitly do not use btn enums here because these are char arrays and btns are shorts]
'[BtnBranchOpen(0x400)][CallOnce(0,"mario_set_spell",1,["ACTION_NULL"])][Jump("magic_list_env")][BtnBranchClose()]\
[end]']


magic_on_plat = ['[AutoNextBox()][JumpLink("magic_gen_shadow_fade_io")][AutoNextBox()]cannot use ACTION while\non ENV platform.[SetSpd(1)][Pause(60)][AutoNextBox()][CallOnce(0,"TE_set_state",2,["&gMagicHUDRequest",0])][EndTransition(0,0,0,0)][TimeEndStr(1)][end]']

no_magic = ['[AutoNextBox()][JumpLink("magic_gen_shadow_fade_io")][AutoNextBox()]Bowser has blocked\n\
all elephant powers.[SetSpd(1)][Pause(60)][AutoNextBox()][CallOnce(0,"TE_set_state",2,["&gMagicHUDRequest",0])][EndTransition(0,0,0,0)][TimeEndStr(1)][end]']


magic_list_chk_cancel = ['\
[BtnBranchOpen(0x20)][CallLoop(0,"TE_set_flag",2,["&gMagicHUDRequest","CANCEL_HUD"])][BtnBranchClose()]\
[BtnBranchOpen(0x4000)][CallLoop(0,"TE_set_flag",2,["&gMagicHUDRequest","CANCEL_HUD"])][BtnBranchClose()]\
cancel[Pop()]']

magic_list_start_cast = ['[CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","START_CAST"])][Pause(1)][CallLoop(1,"TE_get_flag",2,["&gMagicHUDRequest","CASTING_SEL"])]\
[MatchRtrn(1,0)][not matching, do generic cancel check][JumpLink("magic_list_chk_cancel")][end][MatchRtrn(1,1)][Pop()]']

magic_list_spells = [
#end of the spells
'[CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","CAST_SPELL"])][AutoNextBox()][MosaicBGBox(24,94,214,234,"magic_action_menu",2,1)][CallOnce(3,"Get_Spell_Sel",1,[1])][ShadedBGBox(14,110,194,215,0,0,0,0x96)]\n\
Return[CallOnce(0,"mario_set_spell",1,["ACTION_RETURN"])][Jump("magic_spirit_list_end")]\
[GenericText()][end]']


magic_spirit_list_end = ['[SetSpd(1)][Pause(120)][AutoNextBox()][CallOnce(0,"TE_set_state",2,["&gMagicHUDRequest",0])][TimeEndStr(1)]']

magic_list_spirit = ['[CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","CAST_SPIRIT"])][AutoNextBox()][MosaicBGBox(24,94,214,234,"magic_action_menu",2,1)][CallOnce(3,"Get_Spell_Sel",1,[2])][ShadedBGBox(14,110,194,215,0,0,0,0x96)]\n\
Gigantify[CallOnce(0,"mario_set_spell",1,["ACTION_GIGANTIFY"])][Jump("magic_spirit_list_end")]\
[end]']


magic_list_env = ['[CallOnce(0,"mario_set_spell",1,["ACTION_CANCEL_ENV"])][SetSpd(1)][Pause(1)][SetSpd(0)][CallOnce(0,"TE_set_flag",2,["&gMagicHUDRequest","CAST_ENVIRONMENT"])][AutoNextBox()][MosaicBGBox(24,94,214,234,"magic_action_menu",2,1)][CallOnce(3,"Get_Spell_Sel",1,[3])][ShadedBGBox(14,110,194,215,0,0,0,0x96)]\n\
Ice Block[CallOnce(0,"mario_set_spell",1,["ACTION_ICE_BLOCK"])][Jump("magic_spirit_list_end")]\
[end]']


magic_gen_shadow_fade_io = ['[EndTransition(10,0,0,0)][StartTransition(10,0,0,0)][ShadowText(1)][Pop()]']
magic_cannot_place_floor = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]ice block must be placed on floor[TimeEndStr(60)]"]
magic_cannot_place_ceil = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]hanging leaf must be under a ceiling[TimeEndStr(60)]"]
magic_cannot_place_oob = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]floating cloud cannot be placed out of bounds[TimeEndStr(60)]"]

magic_spirit_cancel = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]spirit magic cancelled[TimeEndStr(60)]"]


magic_no_swaps = ['[JumpLink("magic_gen_shadow_fade_io")][AutoNextBox()]No swaps in range[Jump("magic_spirit_list_end")]']
magic_choose_swap = ['[MosaicBGBox(24,94,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,110,194,215,0,0,0,0x96)]\n\
Swap with obj [UsrStr(0)][end]']


magic_choose_return = ['[MosaicBGBox(24,94,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,110,158,215,0,0,0,0x96)]\n\
Select Option[DialogOptions(2)]\
Return[end]\
Recast[end]\
Cancel Cast[end]\
[MosaicBGBox(24,94,214,234,"magic_action_menu",2,1)][ShadedBGBox(14,110,194,215,0,0,0,0x96)]\n\
[DialogResponse(0)][StartDialogBracket(1)]Returning[CallOnce(0,"TE_set_state",2,["&gReturn",2])][EndDialogBracket(1)]\
[DialogResponse(1)][StartDialogBracket(1)]Recasting[CallOnce(0,"TE_set_state",2,["&gReturn",3])][EndDialogBracket(1)]\
[DialogResponse(2)]Cancelling[CallOnce(0,"TE_set_state",2,["&gReturn",4])]\
[GenericText()][Jump("magic_spirit_list_end")]']