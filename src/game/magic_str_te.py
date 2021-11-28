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
headers = (r'#include "src/game/segment2.h"',)

magic_spells_init = ['[StartTransition(8,255,0,0)][AutoNextBox()]\
[MosaicBGBox(14,82,214,234,"magic_action_menu",2,1)]\n\
[BoxTransition(0,0,-72,0)]\
[SetScissor(16,80,230,230)]\
[ShadedBGBox(16,80,158,215,0,0,0,0x96)]\
[PrintGlyph("magic_d_up")]ITEMS\n\
[PrintGlyph("magic_d_left")]SPELLS\n\
[PrintGlyph("magic_d_right")]SPIRIT\n\
[PrintGlyph("magic_d_down")]ENV[end]']