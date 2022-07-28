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
externs = ("extern const Gfx star_seg3_dl_0302B870[];","extern u8 *print_script_IO_TE(u16 siz);","extern u8 *print_script_chan_TE(u16 siz);","extern u8 *print_cur_sel(u16 siz);","extern u8 *print_script_seq_TE(u16 siz);","extern u8 *print_script_mem_TE(u16 siz);")
#These are header files included in this file. Use single quotes so double quotes are delimited for filename
headers = (r'#include "actors/common1.h"',r'#include "textures.h"',)
#This keyboard is required for Text Engine usage. Do not delete
TE_KEYBOARD_lower = ["[ShadedBGBox(0x3E,0x104,0x18,0x78,0x20,0x20,0x20,0x80)][ShadedBGBox(0x28,0x118,0x98,0xb8,0x20,0x20,0x20,0x80)][ScaleText(1.75,1.25)][this is a test comment][TransAbs(0x41,96)] 0 1 2 3 4 5 6 7 8 9\n",
#You can also put comments in with a '#'. 
#Just make sure to end the string before hand.
"  q w e r t y u i o p\n\
 a s d f g h j k l :\n\
  z x c v b n m"," & ? !\n\
  ^  SPACE   END  -[TransAbs(0x30,0x9C)]","[StartKeyboard(0)][Pad()][Pad()][StartKeyboard(0)]"]
#This keyboard is required for Text Engine usage. Do not delete
TE_KEYBOARD_upper = ["[ShadedBGBox(0x3E,0x104,0x18,0x78,0x20,0x20,0x20,0x80)]","[ShadedBGBox(0x28,0x118,0x98,0xb8,0x20,0x20,0x20,0x80)][ScaleText(1.75,1.25)]","[TransAbs(0x41,96)] 0 1 2 3 4 5 6 7 8 9\n\
  Q W E R T Y U I O P\n\
 A S D F G H J K L :\n\
  Z X C V B N M & ? !\n\
  ^  SPACE   END  -[TransAbs(0x30,0x9C)]","[StartKeyboard(0)]","[Pad()][Pad()][StartKeyboard(0)]"]
#These are test strings used to test TE features. They can be viewed by setting TE_debug to 1 in
#text_engine.h and pressing D pad down inside a level.
TEST_BOX = ["[ShadedBGBox(32,298,32,228,0x20,0x20,0x20,0x80)][Pop()]"]
TEST_TEX_BOX = ["[MosaicBGBox(32,96,96,160,0x09000000,3,3)][Pop()]"]
TEST_STR = ["[JumpLink('TEST_BOX')][JumpLink('TEST_TEX_BOX')]\
[SetEnv(30,255,255,255)][WordWrap(296)]Empy test for now. Nothing happening[AbtnEndStr()]\
[end]"]

free_mario = "[BtnBranchOpen(0xD000)][MarioAction('ACT_IDLE')][BtnBranchClose()]"
auto = "[AutoNextBox()]"
nxt_tx = "[SetSpd(1)][Pause(32)][AbtnNextBox()][SetSpd(0)]"
nxt = "[AbtnNextBox()]"
end = "[AbtnEndStr(20)]"
end_tx = f"[SetSpd(1)][Pause(32)]{free_mario}[AbtnEndStr()]"
setup = "[JumpLink('EXP_START')][JumpLink('EXP_BOX')]"
box = "[JumpLink('EXP_BOX')]"

EXP_BOX = ["[ShadedBGBox(14,308,16,120,0x20,0x20,0x20,0x80)][Pop()]"]
EXP_START = [f"[SetOrigin(18,104)][WordWrap(306)][EnBlip()][StartTransition(32,0,0,0)]{auto}[EndTransition(32,0,0,0)][Pop()]"]

#round 1
EE_Explain = [f"{setup}Origin: SM74EE\n\
Course: Veneno Sphere\n\
Star: WorldWide Pain (Star 5){end_tx}"]

SR25_Explain = [f"{setup}Origin: Star Revenge 2.5\n\
Course: Bowser’s Orbital Fortress\n\
Star: Boss Entry{end_tx}"]

SM64MC_Explain = [f"{setup}Origin: Super Mario Master's Challenge\n\
Course: Old Sandy Slide\n\
Star: Secrets{end_tx}"]

Sotb2_Explain = [f"{setup}Origin: Star's of the Beast 2\n\
Course: First Challenge{end_tx}"]

SMtDS_Explain = [f"{setup}Origin: Super Mario the Dark Stars\n\
Course: Chaotic Cube Collection{end_tx}"]

SSoW_Explain = [f"{setup}Origin: Silver Stars of Wisdom\n\
Course: Checkered Parkour Fortress\n\
Star: Deadly Rooftop (Star 3){end_tx}"]

#round 2

KBR2_Explain = [f"{setup}Origin: King Boo's Revenge 2\n\
Course: Variety Dimension\n\
Star: Triforce (Star 3){end_tx}"]

KBRX_Explain = [f"{setup}Origin: King Boo's Revenge X\n\
Course: Stardust Constellation\n\
Star: Three Floors One You (Star 6){end_tx}"]

SMSD_Explain = [f"{setup}Origin: Super Mario Senseless Delirium\n\
Course: Final Delirium{end_tx}"]

NoD_Explain = [f"{setup}Origin: Star Revenge 2: Night of Doom\n\
Course: Tricky Tower's Trials\n\
Star: 2nd Red Coin Hunting (Star 3){end_tx}"]

#finals

TW_Explain = [f"{setup}Origin: Super Mario Treasure World\n\
Course: Toasted Coast\n\
Star: Collecting the Legacy Flags (Star 6){end_tx}"]

TbbT_Explain = [f"{setup}Origin: TsucnenT's Boss Battle Test\n\
Course: After the Rain\n\
Star: Flurry Traveler (Star 6){end_tx}"]