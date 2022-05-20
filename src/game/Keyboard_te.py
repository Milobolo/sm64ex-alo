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
externs = ("extern const Gfx star_seg3_dl_0302B870[];","extern void Star_Anime_Goomba_Cutscene(void);","extern u8 GetCurrentCutscene(void);","extern u32 DorriCutsceneFlags;",)
#These are header files included in this file. Use single quotes so double quotes are delimited for filename
headers = (r'#include "actors/common1.h"',r'#include "textures.h"',r'#include "src/game/segment2.h"',r'#include "src/game/behavior_actions.h"',r'#include "src/game/save_file.h"',)
#This keyboard is required for Text Engine usage. Do not delete
TE_KEYBOARD_lower = ["[ShadedBGBox(0x3E,0x106,0x18,0x78,0x20,0x20,0x20,0x80)][ShadedBGBox(0x28,0x118,0x98,0xb8,0x20,0x20,0x20,0x80)][ScaleText(1.75,1.25)][this is a test comment][TransAbs(0x41,96)] 0 1 2 3 4 5 6 7 8 9\n",
#You can also put comments in with a '#'. 
#Just make sure to end the string before hand.
"  q w e r t y u i o p\n\
 a s d f g h j k l :\n\
  z x c v b n m"," & ? !\n\
  ^  SPACE   END  -[TransAbs(0x30,0x9C)]","[StartKeyboard(0)][Pad()][Pad()][StartKeyboard(0)]"]
#This keyboard is required for Text Engine usage. Do not delete
TE_KEYBOARD_upper = ["[ShadedBGBox(0x3E,0x106,0x18,0x78,0x20,0x20,0x20,0x80)]","[ShadedBGBox(0x28,0x118,0x98,0xb8,0x20,0x20,0x20,0x80)][ScaleText(1.75,1.25)]","[TransAbs(0x41,96)] 0 1 2 3 4 5 6 7 8 9\n\
  Q W E R T Y U I O P\n\
 A S D F G H J K L :\n\
  Z X C V B N M & ? !\n\
  ^  SPACE   END  -[TransAbs(0x30,0x9C)]","[StartKeyboard(0)]","[Pad()][Pad()][StartKeyboard(0)]"]
  
#These are test strings used to test TE features. They can be viewed by setting TE_debug to 1 in
#text_engine.h and pressing D pad down inside a level.


String_Setup = ["[ShadedBGBox(14,298,35,104,0x20,0x20,0x20,0x80)][SetOrigin(16,89)][WordWrap(296)][SetSpd(1)][FFSpd(-1)][EnBlip()][LowerVolume()][Pop()]"]

String_Box = ["[ShadedBGBox(14,298,35,104,0x20,0x20,0x20,0x80)][Pop()]"]

MrI_Img = ["[TexBGBox(16,48,108,140,'MrI_portrait')][Pop()]"]
Blizzard_Img = ["[TexBGBox(16,48,108,140,'blizzard_portrait')][Pop()]"]
Mario_Img = ["[TexBGBox(16,48,108,140,'mario_portrait')][Pop()]"]
Dorrie_Img = ["[TexBGBox(16,48,108,140,'dorrie_portrait')][Pop()]"]
Buddy_Img = ["[TexBGBox(16,48,108,140,'pink_bobomb_portrait')][Pop()]"]
Chuckya_Img = ["[TexBGBox(16,48,108,140,'chuckya_portrait')][Pop()]"]
Chomp_Img = ["[TexBGBox(16,48,108,140,'chomp_portrait')][Pop()]"]
Koopa_Img = ["[TexBGBox(16,48,108,140,'koopa_portrait')][Pop()]"]
Goomba_Img = ["[TexBGBox(16,48,108,140,'goomba_portrait')][Pop()]"]


Mission_Setup = ["[ShadowText(1)][SetOrigin(256,58)][SetSpd(0)][NoFFSpd()]\
[StartTransition(128,64,0x80,240)][WordWrap(0)]\
[Pop()]"]

Abtn_String_End = ["[AbtnNextBox()][MarioAction('ACT_IDLE')][TimeEndStr(1)][end]"]

Thread_O_Prophecy = ["\
[JumpLink('String_Box')]With your actions the thread of prophecy has ended.[Pause(28)] The world has fallen to anime \
and may never return to it's former glory.[AbtnNextBox()][MarioAction('ACT_END_WAVING_CUTSCENE')][end]"]


Intro_Sequence = ["[CallOnce(0,'Check_Cur_Course_Stars',0,[])][MatchRtrn(0,1)][MarioAction('ACT_IDLE')][TimeEndStr(1)][end][GenericText()]\
[CallOnce(0,'Star_Anime_Goomba_Cutscene',0,[])][JumpLink('String_Setup')][JumpLink('Mario_Img')]\
A beautiful day.\n[Pause(24)]Just me,[Pause(12)] my board,[Pause(12)] and the wind.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')]\
There's no better feeling than to dissociate from the stresses of the world, [Pause(14)]\
and reconnect to nature.[Pause(24)] Especially here in this beautiful hidden beach behind the castle![AbtnNextBox()]\
[CallOnce(0,'TE_set_state',2,['&gTEAdvCutscene',1])][Pause(300)][Jump('Intro_Sequence_Cutscene_1')][end]\
[GenericText()][end]"]

Intro_Sequence_Cutscene_1 = ["[AutoNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')]\
Oh no!![Pause(28)]\n\
I've come to escape the cringe within,[Pause(12)] only to be met with a greater power in the wild.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')]\
[CallOnce(0,'TE_set_state',2,['&gTEAdvCutscene',1])]How am I going to relax when these anime lovers are out enjoying themselves?!?[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')]\
I need to do something about these people and fast,[Pause(14)] or else I'll never \
get to enjoy this secret beach again![AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')]\
[CallOnce(0,'TE_set_state',2,['&gTEAdvCutscene',1])][Pause(150)]\
Wow![Pause(28)] Deodorant!![Pause(28)]\n\
I know exactly how to scare away \
these anime lovers,[Pause(12)] and I'll get to shred some waves at the same time!![AbtnNextBox()]\
[CallOnce(0,'TE_set_state',2,['&gTEAdvCutscene',1])][JumpLink('Mission_Setup')][AutoNextBox()][EndTransition(64,0,0,0)][SetSfx(0x3030)]\
OBJECTIVE: COLLECT 8 STICKS OF DEODERANT[SetSpd(1)][Pause(128)][MarioAction('ACT_IDLE')][SetSfx(0x314D)][Pause(64)][TimeEndStr(5)]\
[end]"]

PowerWord = ["[SetEnv(0xFF,0,0,0xFF)][UsrStr(0)][SetEnv(0xFF,0xFF,0xFF,0xFF)][Pop()]"]

PowerWordTest = ["[JumpLink('String_Setup')][JumpLink('Buddy_Img')]Your power word is [JumpLink('PowerWord')][Jump('Abtn_String_End')]"]

Buddy_Slope_Explain = ["[JumpLink('String_Setup')][JumpLink('Buddy_Img')]Trying to go up a slope with your shell will make you go backwards instead.[Pause(40)] \
When going up a slope, try to jump over it instead of riding up it.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Buddy_Img')]\
Though if you try to jump on slopes leading to the ether like this rock next to me,[Pause(18)] your shell will be destroyed.[Pause(40)] \
All that lies past these walls is a void of nothingness.\
[Jump('Abtn_String_End')]"]

DorrieForestTalk = ["[JumpLink('String_Setup')][JumpLink('Dorrie_Img')]\
You have come far mario.[Pause(40)] You have shown bravery and perseverance to make it to me here.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
With this,[Pause(18)] your training is complete.[Pause(30)] I will impart upon you the golden knowledge needed to defeat anime.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
Think of the anime viewer,[Pause(18)] their vile evil rank minds know only hedonism.[Pause(30)] \
They refuse to pursue self improvement,[Pause(18)] integrate into society,[Pause(18)] and work towards a common good.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
They're aware of their faults,[Pause(18)] yet refuse to dwell on them.[Pause(30)] Instead they run from their problems by diving deeper into escapsim with anime.[Pause(30)] \
Their greatest enemy is themselves.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
Insult,[Pause(18)] scream and belittle the weeabo and it does nothing,[Pause(18)] but show them their true selves,[Pause(18)] and \
watch them revel in despair,[Pause(18)] and wither away into nothingness.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
This is no simple task,[Pause(18)] but can be done by calling upon a word of power and hope. [Pause(30)]\
Something dear to your heart,[Pause(18)] which will shine a light of justice upon them.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
A cranial shock to break the spell controlling them,[Pause(18)] vetting them the clarity needed for reflection.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
Choose your power word carefully Mario.[Pause(30)] Once chosen,[Pause(18)] I will lock it within you using the power \
of the stars.[Pause(30)] Then simply shout the power word at an anime villain to destroy them.[AbtnNextBox()]\
[WordWrap(0)][StartKeyboard(0)][AutoNextBox()][CallOnce(0,'Save_Power_Word',0,[])][WordWrap(296)][JumpLink('String_Box')][JumpLink('Dorrie_Img')]Now take this star,[Pause(18)] and use your new powers wisely.\
[Jump('Abtn_String_End')]"]

Dorrie_Invite = ["[JumpLink('String_Setup')][CallOnce(0,'Dorrie_Invite_Cutscene',0,[])]\
[CallOnce(0,'TE_set_state',2,['&DorriCutsceneFlags',1])][Pause(90)][CallLoop(0,'TE_get_state',1,['&DorriCutsceneFlags'])][MatchRtrn(0,1)]\
[JumpLink('Dorrie_Img')]Hello Mario,[Pause(12)] I am on a quest to end anime![Pause(28)] Will you join me?[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')][SetSpd(0)][NoFFSpd()]\
[TransOffs(0,14)][DialogOptions(1)]Yes, anime has enjoyed its position of power for too long[end]\
Sorry fellow anti anime warrior, but I no longer feel the rage of a man against the world.[end][SetSpd(1)][FFSpd(-1)][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
[DialogResponse(0)]Perfect,[Pause(28)] let us enter the league of evil together and being our plotting![AbtnNextBox()]\
[CallOnce(0,'TE_set_state',2,['&gTEAdvCutscene',1])][MarioAction('ACT_IDLE')][TriggerWarp(15,0x12)][TimeEndStr(5)]\
[DialogResponse(1)]Fool,[Pause(28)] he who ignores the great evil is eventually consumed by it.[Pause(28)] \
You shall suffer in eternal hell for being a bystander.[Pause(28)] Do you understand?[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Mario_Img')][TransOffs(0,14)][DialogOptions(0)]Yes I understand.[end]\
[Jump('Thread_O_Prophecy')]\
[if waiting for cutscene go all the way to end here][GenericText()][end]\
"]


Shell_Tutorial = ["[JumpLink('String_Setup')][JumpLink('Buddy_Img')]Do you even shell Mario?[Pause(28)] I see you out here posin',[Pause(12)] don't lie.[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Buddy_Img')]Don't worry,[Pause(12)] I'm no nark,[Pause(12)] I'll even help you out.[Pause(28)] What do you need to know?[AbtnNextBox()][SetRtrn(0)]\
[JumpLink('String_Box')][JumpLink('Mario_Img')][TransOffs(0,14)][SetSpd(0)][NoFFSpd()][DialogOptions(3)]\
Shell Basics[end]\
Speed Boosting[end]\
Water Movement[end]\
Nothing[end]\
[SetSpd(1)][FFSpd(-1)][JumpLink('String_Box')][JumpLink('Buddy_Img')]\
[DialogResponse(0)][Jump('Shell_Basics')]\
[DialogResponse(1)][Jump('Air_Movement')]\
[DialogResponse(2)][Jump('Water_Movement')]\
[DialogResponse(3)][Jump('No_Shell_Tut')]\
[end]"]

Shell_Basics = ["You can board a shell anytime on the ground with the L btn.[Pause(28)] Dismount by pressing Z and B or A at the same time.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Buddy_Img')]\
You can slow down by holding Z,[Pause(14)] and boost speed with B.[Pause(28)] While on a shell,[Pause(14)] you can ride on top of water.[AbtnNextBox()][Jump('Shell_Tut_End')]"]

Air_Movement = ["You can double jump in the air while on a shell.[Pause(28)] Press Z while in the air and you'll do a ground pound.[Pause(28)] \
Boost with B before a double jump to clear a large gap.[AbtnNextBox()][Jump('Shell_Tut_End')]"]

Water_Movement = ["Press Z while on water to go underwater.[Pause(28)] You can boost while underwater with the B btn.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Buddy_Img')]\
If you go to the surface while holding the shell,[Pause(14)] you'll jump outside of it automatically.[Pause(28)] Press Z while jumping out of water to land on top of it.[AbtnNextBox()][Jump('Shell_Tut_End')]"]

No_Shell_Tut = ["Ok,[Pause(12)] if you can get all this deodorant then you'll have all you the skills you need anyway.[Pause(28)] Good luck defeating anime.[Jump('Abtn_String_End')]"]

Shell_Tut_End = ["[JumpLink('String_Box')][JumpLink('Buddy_Img')]Pretty simple right?[Pause(28)] Ya got anymore questions?[DialogOptions(1)]\
Yes[end]\
No, I'm an expert now[end][JumpLink('String_Box')][JumpLink('Buddy_Img')]\
[DialogResponse(0)]Alright,[Pause(12)] what do you wanna know?[AbtnNextBox()][ClearBuffer()][GotoRtrn(0)]\
[DialogResponse(1)]Alright,[Pause(12)] now go show those anime dweebs what a real superstar looks like.[Jump('Abtn_String_End')]"]


AnimeGoomba1 = ["[JumpLink('String_Setup')][JumpLink('Goomba_Img')]\
What does the scouter say about your power level? [Pause(12)][SetSfx(0x2427)]-SNORT-[Pause(52)]\
Haha it's zero LOOOOOOOOLL[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Goomba_Img')]\
If you want to be powerful like us fine gentlesirs.[Pause(28)] You need to dress in fine anime drip.[AbtnNextBox()]\
[TransOffs(0,14)][JumpLink('String_Box')][JumpLink('Mario_Img')][DialogOptions(1)]\
Accept anime drip[end]\
Retain your pride[end]\
[JumpLink('String_Box')][JumpLink('Mario_Img')]\
[DialogResponse(0)][WobbleText(1)]I see the light.[Pause(28)] Kirino Channnnn----- [Pause(20)]kyuuuuuuu---- [Pause(20)]I love youuuuuu,[Pause(16)] mai waifuuuuuu.. \
[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')][SetSfx(0x2427)]-SNORT-[Pause(52)]\
Please sit on my face Kirino Samaaaaaa--------[SetSfx(0x2427)] -SNORT-[AbtnNextBox()][WobbleText(0)][JumpLink('String_Box')]\
You have committed the grave sin of enjoying anime,[Pause(15)] falling to evil's temptations.[Pause(28)]\
You have doomed your future,[Pause(15)] and the future of all good folk in this world.[AbtnNextBox()]\
[Jump('Thread_O_Prophecy')]\
[DialogResponse(1)]I shant fall for the temptations you anime lovers present.[Pause(28)] My heart sings for justice,[Pause(16)] \
a woman finer than any of your [Pause(16)][RQ]wai-[Pause(16)]fus[RQ].[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')]\
Watch me destroy you illusory chateau of sauve you wear like a rag,[Pause(16)] and reveal it to be the \
mansion of cringe it truly is.[Pause(28)] Your days are numbered!\
[Jump('Abtn_String_End')]"]

AnimeGoomba2 = ["[JumpLink('String_Setup')][JumpLink('Goomba_Img')]\
My tsuchinoko tensei will activate if\nyou get any closer...[Pause(45)] \
Watch your step mortal....[Pause(45)] I have a short fuse...[Pause(45)]\n\
[SetSfx(0x5038)]Muahahahahahaha.\
[Jump('Abtn_String_End')]"]

AnimeGoomba3 = ["[JumpLink('String_Setup')][JumpLink('Goomba_Img')]\
Dark magician girl attackkkkk!!!!!!1!!! [Pause(40)]\n\
Doki doki heart piercing love blast!!!\
[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Goomba_Img')]\
Sausuges Lukoi-kun.[Pause(45)] You've survived my dark minion's attack.[Pause(30)] However formidible you may be,[Pause(15)] I \
shant reneg my commitment to your destruction.[Pause(30)] I shall attack again,[Pause(15)] harder and stronger!!\
[Jump('Abtn_String_End')]"]

AnimeGoomba4 = ["[JumpLink('String_Setup')][JumpLink('Goomba_Img')]\
You've attacked so magnificently charles-san-sama...[Pause(30)] \
Subarasushii.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Goomba_Img')]\
Nevertheless...[Pause(45)] I shall hold on forever.[Pause(30)] Despite your dark attacks my pure mind \
is unwavering.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Goomba_Img')]I will never give in.[Pause(30)] Not when I am fueled by the power of \
friendship with Dark Shining Blue Eyed Yellow Feet Buster Dragon!!!\
[Jump('Abtn_String_End')]"]



MrBlizzard1 = [""]
MrBlizzard2 = [""]
MrBlizzard3 = [""]
MrI1 = [""]
MrI2 = [""]
MrI3 = [""]