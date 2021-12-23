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
externs = ("extern const Gfx star_seg3_dl_0302B870[];","extern struct Object *gReturn;")
#These are header files included in this file. Use single quotes so double quotes are delimited for filename
headers = (r'#include "src/game/segment2.h"',r'#include "include/sm64.h"',r'#include "src/game/magic.h"',r'#include "src/game/area.h"')

end_read_sign = ["[MarioAction('ACT_IDLE')][TimeEndStr(1)][end]"]

gigantify_intro_1 = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]While large you can push metal boxes[TimeEndStr(160)]"]
gigantify_intro_2 = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]Normally heavy objects become light[TimeEndStr(160)]"]
gigantify_intro_3 = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]You can use heavy objects to press\nbig switches[TimeEndStr(160)]"]
gigantify_intro_4 = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()]Access the spell in the spirit menu. Recasting\n\
a spirit spell will cancel it[TimeEndStr(160)]"]


#5 lines max
sign_box_setup = ["[ShadedBGBox(28,292,84,176,0,0,0,0x96)][WordWrap(288)][Pop()]"]


gigantify_sign = ["[JumpLink('magic_gen_shadow_fade_io')][AutoNextBox()][JumpLink('sign_box_setup')][TransOffs(70,0)]Trial of spirit\n\n\
[TransOffs(-70,0)]Gigantify - Enlarges the self and over doubles strength. \
Run faster, jump higher and move heavy objects easily.[AbtnNextBox()][Jump('end_read_sign')]"]