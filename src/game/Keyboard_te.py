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
headers = (r'#include "actors/common1.h"',r'#include "textures.h"',r'#include "src/game/segment2.h"',r'#include "src/game/behavior_actions.h"',r'#include "src/game/save_file.h"',
r'#include "src/menu/file_select.h"',)
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


#common strings

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

PrepDiag = ["[TransOffs(0,14)][SetSpd(0)][NoFFSpd()][Pop()]"]
Spd = ["[SetSpd(1)][FFSpd(-1)][Pop()]"]

Mission_Setup = ["[ShadowText(1)][SetOrigin(256,58)][SetSpd(0)][NoFFSpd()]\
[StartTransition(128,64,0x80,240)][WordWrap(0)]\
[Pop()]"]

Abtn_String_End = ["[AbtnNextBox()][MarioAction('ACT_IDLE')][TimeEndStr(1)][end]"]

Thread_O_Prophecy = ["\
[JumpLink('String_Box')]With your actions the thread of prophecy has ended.[Pause(28)] The world has fallen to anime \
and may never return to it's former glory.[AbtnNextBox()][MarioAction('ACT_END_WAVING_CUTSCENE')][end]"]


#tutorial beach

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

Dorrie_Invite = ["[JumpLink('String_Setup')][CallOnce(0,'Dorrie_Invite_Cutscene',0,[])]\
[CallOnce(0,'TE_set_state',2,['&DorriCutsceneFlags',1])][Pause(90)][CallLoop(0,'TE_get_state',1,['&DorriCutsceneFlags'])][MatchRtrn(0,1)]\
[JumpLink('Dorrie_Img')][SetSfx(0x5037)]Hello Mario,[Pause(12)] I am on a quest to end anime![Pause(28)] Will you join me?[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')]\
[JumpLink('PrepDiag')][DialogOptions(1)]Yes, anime has enjoyed its position of power for too long[end]\
Sorry fellow anti anime warrior, but I no longer feel the rage of a man against the world.[end][JumpLink('Spd')][JumpLink('String_Box')][JumpLink('Dorrie_Img')][SetSfx(0x5037)]\
[DialogResponse(0)]Perfect,[Pause(28)] let us enter the league of evil together and begin our plotting![AbtnNextBox()]\
[CallOnce(0,'TE_set_state',2,['&gTEAdvCutscene',1])][MarioAction('ACT_IDLE')][TriggerWarp(15,0xB)][TimeEndStr(5)]\
[DialogResponse(1)]Fool,[Pause(28)] he who ignores the great evil is eventually consumed by it.[Pause(28)] \
You shall suffer in eternal hell for being a bystander.[Pause(28)] Do you understand?[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Mario_Img')][JumpLink('PrepDiag')][DialogOptions(0)]Yes I understand.[end]\
[JumpLink('Spd')][Jump('Thread_O_Prophecy')]\
[if waiting for cutscene go all the way to end here][GenericText()][end]\
"]


Shell_Tutorial = ["[JumpLink('String_Setup')][JumpLink('Buddy_Img')]Do you even shell Mario?[Pause(28)] I see you out here posin',[Pause(12)] don't lie.[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Buddy_Img')]Don't worry,[Pause(12)] I'm no nark,[Pause(12)] I'll even help you out.[Pause(28)] What do you need to know?[AbtnNextBox()][SetRtrn(0)]\
[JumpLink('String_Box')][JumpLink('Mario_Img')][JumpLink('PrepDiag')][DialogOptions(3)]\
Shell Basics[end]\
Speed Boosting[end]\
Water Movement[end]\
Nothing[end]\
[JumpLink('Spd')][JumpLink('String_Box')][JumpLink('Buddy_Img')]\
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
[JumpLink('String_Box')][JumpLink('Mario_Img')][JumpLink('PrepDiag')][DialogOptions(1)]\
Accept anime drip[end]\
Retain your pride[end]\
[JumpLink('Spd')][JumpLink('String_Box')][JumpLink('Mario_Img')]\
[DialogResponse(0)][WobbleText(1)]I see the light.[Pause(28)] Kirino Channnnn----- [Pause(20)]kyuuuuuuu---- [Pause(20)]I love youuuuuu,[Pause(16)] mai waifuuuuuu.. \
[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')][SetSfx(0x2427)]-SNORT-[Pause(52)]\
Please sit on my face Kirino Samaaaaaa--------[SetSfx(0x2427)] -SNORT-[AbtnNextBox()][WobbleText(0)][JumpLink('String_Box')]\
You have committed the grave sin of enjoying anime,[Pause(15)] falling to evil's temptations.[Pause(28)]\
You have doomed your future,[Pause(15)] and the future of all good folk in this world.[AbtnNextBox()]\
[Jump('Thread_O_Prophecy')]\
[DialogResponse(1)]I shant fall for the temptations you anime lovers present.[Pause(28)] My heart sings for justice,[Pause(16)] \
a woman finer than any of your [Pause(16)]\n\
[RQ]wai-[Pause(16)]fus[RQ].[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Mario_Img')]\
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


#The backrooms

MrBlizzardWF = ["[JumpLink('String_Setup')][JumpLink('Blizzard_Img')]\
[SetSfx(0x500B)]HAHAHAHA![Pause(32)] you've been tricked IDIOT.[Pause(32)] \
You can't trick me,[Pause(16)] us anime viewers have superior intellect.[Pause(32)] \
You'd have to be a dumbass to fall for that sorry acting![Pause(32)][SetSfx(0x500B)] HAHAHAHA![AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
My boss will deal with you,[Pause(16)] you poked the wrong establishment.[Pause(32)] \
Prepare for death![Pause(32)][SetSfx(0x500B)] HAHAHAHAHA!\
[AbtnNextBox()][JumpLink('Mission_Setup')][AutoNextBox()]\
[EndTransition(64,0,0,0)][SetSfx(0x3030)]\
OBJECTIVE: DEFEAT GAMESTOP BOSS[SetSpd(1)][Pause(128)][MarioAction('ACT_IDLE')][SetSfx(0x314D)][Pause(64)][TimeEndStr(5)]\
[end]"]


#game stop

GS_Dorrie_Intro = ["[JumpLink('String_Setup')][JumpLink('Dorrie_Img')]\
[SetSfx(0x5037)]Game stop is a high traffic area for the weaboos.[Pause(32)] My dorrie senses \
are telling me that this is a hotspot for anime distribution.\
[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
If we want to get to the bottom of the anime problem \
we're gonna need firsthand info.[Pause(32)] \
Once you find something suspicious let me know.\
[AbtnNextBox()][JumpLink('Mission_Setup')][AutoNextBox()]\
[EndTransition(64,0,0,0)][SetSfx(0x3030)]\
OBJECTIVE: TRACK DOWN ANIME OPERATIONS[SetSpd(1)][Pause(128)][MarioAction('ACT_IDLE')][SetSfx(0x314D)][Pause(64)][TimeEndStr(5)]\
[end]"]

AnimeKoopa1 =["[JumpLink('String_Setup')][JumpLink('Koopa_Img')]\
My dark intellect tells me you're a fellow cursed one...[Pause(52)] \
Pray tell your affliction comrade.[Pause(32)] What must you endure?[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Mario_Img')][JumpLink('PrepDiag')][DialogOptions(1)]\
Shutup dweeb I'm not cursed.[end]\
My black fiend blood compels me to game. It is \
an everlasting stain upon my accursed soul[end]\
[JumpLink('Spd')][JumpLink('String_Box')][JumpLink('Koopa_Img')]\
[DialogResponse(0)]Wow that's rude.[Pause(32)] Come back when you learn \
the manners of a fine gentlesir like yours truly.\
[DialogResponse(1)]We share a deep bond.[Pause(32)] I too am cursed to roam \
this planet in search of the fine art known to mortals \
as gaming.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Koopa_Img')]\
Life is fleeting for [Pause(32)][SetSpd(0)][NoFFSpd()][SetEnv(0xFF,0,0,0xFF)]CursedBloods[SetEnv(0xFF,0xFF,0xFF,0xFF)][JumpLink('Spd')][Pause(32)] like us.[Pause(32)] We must treasure \
every moment.[Pause(32)] I will take my leave now.[Pause(32)] \
Should fate deem we meet again our destiny will be \
truly epic.\
[GenericText()][Jump('Abtn_String_End')]"]


MrBlizzard1 = ["[JumpLink('String_Setup')][JumpLink('Blizzard_Img')]\
Hello sir, welcome to GameStop.[Pause(32)] How \
can I help you this fine day?[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Mario_Img')][JumpLink('PrepDiag')][DialogOptions(2)]\
Ask about anime and games.[end]\
Ask about manager.[end]\
Bluff your way into backroom.[end]\
[JumpLink('Spd')][JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
[DialogResponse(0)]\
Anime fans have always been gaming fans.[Pause(26)] \
It's in our business to support them.[Pause(26)] Nothing weird \
about that hahaha.\
[DialogResponse(1)]\
The boss was always an avid gamer.[Pause(30)] Only recently \
has he been into anime.[Pause(38)] It's weird because he totally \
isn't the type to go 3 weeks without a shower.\
[DialogResponse(2)]\
A plumber you say?[Pause(42)] What's the building's \
password then?[AbtnNextBox()]\
[WordWrap(0)][ResetKeyboard()][StartKeyboard(1)][AutoNextBox()][WordWrap(296)]\
[CallOnce(0,'TE_check_password',2,['GS_password',1])][JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
[MatchRtrn(0,0)]You're lying man.[Pause(26)] Just another fake weeb trying \
to get into the anime clubhouse.\
[MatchRtrn(0,1)]\
Awesome,[Pause(16)] you really are our plumber.[Pause(38)] Let me take you straight to our secret \
establishment.[Pause(24)] We've always had toilet problems.[Pause(34)] It \
wasn't designed for such heavy loads I've heard.\
[AbtnNextBox()]\
[MarioAction('ACT_IDLE')][TriggerWarp(15,0xB)][TimeEndStr(5)][end]\
[GenericText()][Jump('Abtn_String_End')]"]

MrBlizzard2 = ["[JumpLink('String_Setup')][JumpLink('Blizzard_Img')]\
Hi welcome to GameStop,[Pause(18)] I hate myself.[Pause(42)]\n\
Would you like to pre-order the new call of battle:[Pause(15)] \
bloody warfare 3 battle war edition?[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
It comes with the limited edition battle \
war bloody combat suit and 500 clumbo points.[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Mario_Img')][JumpLink('PrepDiag')][DialogOptions(0)]\
No thank you I just need some info.[end]\
[JumpLink('Spd')][JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
Wonderful.[Pause(32)] Can I get your phone number and \
credit card?[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Mario_Img')][JumpLink('PrepDiag')][DialogOptions(0)]\
I don't want the game.[end]\
[JumpLink('Spd')][JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
Oh I see.....[Pause(52)] \
You must be one of those anime gamers then...[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
How wonderful.[Pause(32)] I assume you want the new \
hit release,[Pause(38)] [RQ]My Little Sister's Cute Hemerrhoids?[RQ][AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
Or is there something else on your rada-[Pause(22)] ahem...[Pause(32)] \
I mean, or do you have a different [Pause(32)][RQ]buraddi dezaia[RQ][Pause(32)] dark-lord sama?[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Mario_Img')]\
This guy is totally sucking up to the weaboos.[Pause(32)] Something stinks about this.[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Mario_Img')][JumpLink('PrepDiag')][DialogOptions(0)]\
No thanks I'm not a virigin. I'll take call of battle 3[end]\
[JumpLink('Spd')][JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
Oh thank goodness.[Pause(32)] We appreciate your business sir.\
[Jump('Abtn_String_End')]"]

MrBlizzard3 = ["[JumpLink('String_Setup')][JumpLink('Blizzard_Img')]\
I hate anime as much as the next guy,[Pause(16)] but \
the weebs basically finance this whole store.[Pause(32)] The boss \
sold his soul for the money.\
[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Blizzard_Img')]\
As gamers we were supposed \
to save the world not doom it.[Pause(32)] \
I hope someone sets him straight.\
[Jump('Abtn_String_End')]"]


MrI1 = ["[JumpLink('String_Setup')][JumpLink('MrI_Img')]\
I'm more comfortable here in the corner.[Pause(32)] \
Its scary out in the open.[Pause(32)] As a gamer,[Pause(18)] there's always someone \
trying to sneak around me and spin me out.\
[AbtnNextBox()][JumpLink('String_Box')][JumpLink('MrI_Img')]\
Keep your enemies close and watch your back.[Pause(32)] \
That's my motto.\
[Jump('Abtn_String_End')]"]

MrI2 = ["[JumpLink('String_Setup')][JumpLink('MrI_Img')]\
Us gamers hate those anime weirdos as much \
as you do Mario.[Pause(32)] They're giving gaming a bad name![Pause(32)] \
They have no self awareness.\
[AbtnNextBox()][JumpLink('String_Box')][JumpLink('MrI_Img')]\
You don't have dark powers \
mates,[Pause(16)] you're just cringe.[Pause(32)] If it was up to me I'd kill them all \
in a bloody murder purge hahahahahahahaa.[Pause(32)]\n\
ahem....[Pause(42)] Don't look in my garage...\
[Jump('Abtn_String_End')]"]

MrI3 = ["[JumpLink('String_Setup')][JumpLink('MrI_Img')]\
Gamers and weaboos aren't so different really.[Pause(32)] \
We're both shunned and scorned by society.\
[AbtnNextBox()][JumpLink('String_Box')][JumpLink('MrI_Img')]\
The fundamental difference is that weebs deserve it.[Pause(32)] Gamers \
need to stand up against anime,[Pause(16)] not just for ourselves but for \
everyone.\
[Jump('Abtn_String_End')]"]

#Pocketed Forest

ForestIntro = ["[JumpLink('String_Setup')][JumpLink('Dorrie_Img')]\
[SetSfx(0x5037)]The anime orchestrators are aware of our plans to defeat them.[Pause(32)] \
You need to grow stronger to defeat them.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
This trial will test your shell shredding abilities,[Pause(16)] and prove yourself\
worthy of defeating anime once and for all.\
[AbtnNextBox()][JumpLink('Mission_Setup')][AutoNextBox()]\
[EndTransition(64,0,0,0)][SetSfx(0x3030)]\
OBJECTIVE: COMPLETE FOREST TRIAL[SetSpd(1)][Pause(128)][MarioAction('ACT_IDLE')][SetSfx(0x314D)][Pause(64)][TimeEndStr(5)]\
[end]"]


PowerWord = ["[SetSfx(0x500C)][SetEnv(0xFF,0,0,0xFF)][UsrStr(0)][SetEnv(0xFF,0xFF,0xFF,0xFF)][Pop()]"]

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
This is no simple task,[Pause(18)] but can be done by calling upon a word of power and hope.[Pause(30)] \
Something dear to your heart,[Pause(18)] which will shine a light of justice upon them.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
A cranial shock to break the spell controlling them,[Pause(18)] vetting them the clarity needed for reflection.[AbtnNextBox()][JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
Choose your power word carefully Mario.[Pause(30)] Once chosen,[Pause(18)] I will lock it within you using the power \
of the stars.[Pause(30)] Then simply shout the power word at an anime villain to destroy them.[AbtnNextBox()]\
[WordWrap(0)][StartKeyboard(0)][AutoNextBox()][CallOnce(0,'Save_Power_Word',0,[])][WordWrap(296)][JumpLink('String_Box')][JumpLink('Dorrie_Img')][SetSfx(0x5037)]Now take this star,[Pause(18)] and use your new powers wisely.\
[Jump('Abtn_String_End')]"]

DorrieForestReTalk = ["[JumpLink('String_Setup')][JumpLink('Dorrie_Img')]Do you want to change your word of power?[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Dorrie_Img')][JumpLink('PrepDiag')][DialogOptions(1)]\
Yes[end]\
No[end]\
[DialogResponse(0)][WordWrap(0)][ResetKeyboard()][StartKeyboard(0)][AutoNextBox()][CallOnce(0,'Save_Power_Word',0,[])][WordWrap(296)]\
[GenericText()][JumpLink('Spd')][JumpLink('String_Box')][JumpLink('Dorrie_Img')]Take the start to lock in your power word.[Pause(30)] Use it well to destroy the powers of anime.\
[Jump('Abtn_String_End')]"]


#Lair Of Evil

LairOfEvil1 = ["[JumpLink('String_Setup')][JumpLink('Dorrie_Img')]\
Budget here is a bit low lately.[Pause(30)] Seems no one wants to take up the cause.[Pause(30)] \
Regardless,[Pause(15)] I'm glad to have someone as committed as me here.[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
I already have a mission for you.[Pause(30)] Investigate a suspicious business \
with lots of anime throughput.[Pause(30)] I'll send you there right away,[Pause(16)] gotta strike the iron while it's hot.[AbtnNextBox()]\
[MarioAction('ACT_IDLE')][TriggerWarp(15,0xB)][TimeEndStr(5)][end]\
"]

LairOfEvil2 = ["[JumpLink('String_Setup')][JumpLink('Dorrie_Img')]\
They saw right through us mario.[Pause(30)] You're lucky that guy was a weakling. \
If you want to fight against anime,[Pause(15)] you're gonna need a powerup.[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
I have a trial laid out for you that will increase your strength.[Pause(30)] I'll send you there \
while I track down the source of anime.[AbtnNextBox()]\
[MarioAction('ACT_IDLE')][TriggerWarp(15,0xB)][TimeEndStr(5)][end]\
"]

LairOfEvil3 = ["[JumpLink('String_Setup')][JumpLink('Dorrie_Img')]\
I've found them![Pause(30)] Of course, it was bowser all along.[Pause(30)] \
Who else would create and spread such a dastardly social plague.[Pause(32)] \
We need to put a stop to this right away.[AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Dorrie_Img')]\
This will be your final mission.[Pause(30)] Destroy bowser and his \
anime minions.[AbtnNextBox()]\
[MarioAction('ACT_IDLE')][TriggerWarp(15,0xB)][TimeEndStr(5)][end]\
"]

#bowser anime consortium

PowerWordDestroy1 = ["[JumpLink('String_Setup')][JumpLink('Mario_Img')]Die Anime Enjoyer![Pause(34)]\n\
[JumpLink('PowerWord')][AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Goomba_Img')][SetSfx(0x3030)][CallOnce(0,'TE_set_state',2,['&gGoombaState',1])]AAAAAAAHHHHHHHHHHHHHHHHHHHHHHHH\n\
I'm dying!!!!!!!!!!!!!!!!\n[Pause(34)]\
le dies of internal cringe.[AbtnNextBox()][MarioAction('ACT_IDLE')][TimeEndStr(5)]"]

#koopa
PowerWordDestroy2 = ["[JumpLink('String_Setup')][JumpLink('Mario_Img')]Become bread!!!![Pause(34)]\n\
[JumpLink('PowerWord')][AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Koopa_Img')][SetSfx(0x3030)][CallOnce(0,'TE_set_state',2,['&gGoombaState',1])]Noooooooooooooooo\n\
I don't want to be bread!!!!!\n[Pause(34)]\
le becomes le bread.[AbtnNextBox()][MarioAction('ACT_IDLE')][TimeEndStr(5)]"]

#Mr I
PowerWordDestroy3 = ["[JumpLink('String_Setup')][JumpLink('Mario_Img')]Even your mom thinks you are cringe![Pause(34)]\n\
[JumpLink('PowerWord')][AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('MrI_Img')][SetSfx(0x3030)][CallOnce(0,'TE_set_state',2,['&gGoombaState',1])]MOOOOOOOOOOOOOMMMMMYYYY\n\
NOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!\n[Pause(34)]\
le is forced to clean le room.[AbtnNextBox()][MarioAction('ACT_IDLE')][TimeEndStr(5)]"]

#mr Blizzard
PowerWordDestroy4 = ["[JumpLink('String_Setup')][JumpLink('Mario_Img')]Go take a shower stinky anime watcher!![Pause(34)]\n\
[JumpLink('PowerWord')][AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Blizzard_Img')][SetSfx(0x3030)][CallOnce(0,'TE_set_state',2,['&gGoombaState',1])]AAAAAAAHHHHHHHHHHHHHHHHHHHHHHHH\n\
The shower is melting meeeeeeee!!!!!\n[Pause(34)]\
le melts to death in shower.[AbtnNextBox()][MarioAction('ACT_IDLE')][TimeEndStr(5)]"]

PowerWordDestroy5 = ["[JumpLink('String_Setup')][JumpLink('Mario_Img')]No, you are not sasuke![Pause(34)]\n\
[JumpLink('PowerWord')][AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Goomba_Img')][SetSfx(0x3030)][CallOnce(0,'TE_set_state',2,['&gGoombaState',1])]AAAAAAAHHHHHHHHHHHHHHHHHHHHHHHH\n\
My sharingan couldn't save me!!!!!!\n[Pause(34)]\
le dies of internal cringe.[AbtnNextBox()][MarioAction('ACT_IDLE')][TimeEndStr(5)]"]

#koopa
PowerWordDestroy6 = ["[JumpLink('String_Setup')][JumpLink('Mario_Img')]The only dark power you have, is being alone in your room![Pause(34)]\n\
[JumpLink('PowerWord')][AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Koopa_Img')][SetSfx(0x3030)][CallOnce(0,'TE_set_state',2,['&gGoombaState',1])]Noooooooooooooooo\n\
I'm so lonely!!! TFW NO GF!\n[Pause(34)]\
le dies of no le GF sad times.[AbtnNextBox()][MarioAction('ACT_IDLE')][TimeEndStr(5)]"]

PowerWordDestroy7 = ["[JumpLink('String_Setup')][JumpLink('Mario_Img')]I will destroy you!![Pause(34)]\n\
[JumpLink('PowerWord')][AbtnNextBox()]\
[JumpLink('String_Box')][JumpLink('Goomba_Img')][SetSfx(0x3030)][CallOnce(0,'TE_set_state',2,['&gGoombaState',1])]AAAAAAAHHHHHHHHHHHHHHHHHHHHHHHH\n\
I've only just now realized I'm a disappointment to my family!!!!!!\n[Pause(34)]\
le dies of le causes of le death.[AbtnNextBox()][MarioAction('ACT_IDLE')][TimeEndStr(5)]"]


#file select
TE_file_select = ["[SetRtrn(0)][SetEnv(0,0,0,255)][ScaleText(2.0,2.0)][TransOffs(50,0)]DORRIE VS ANIME\n[ScaleText(1.0,1.0)]\
[TransOffs(30,0)][DialogOptions(3)]\
CHOOSE FILE[end]\
ERASE FILE[end]\
COPY FILE[end]\
CREDITS[end]\
[SetEnv(0,0,0,255)][DialogResponse(3)][Jump('DVA_credits')]\
[DialogResponse(2)][StartDialogBracket(1)][CallOnce(0,'TE_set_state',2,['&Op_Type',3])][ScaleText(2.0,2.0)][TransOffs(60,0)]COPY FROM FILE\n[ScaleText(1.0,1.0)][TransOffs(30,0)][DialogOptions(4)]\
MARIO A: [CallLoop(1,'TE_print_star_cnt',3,[0,0,0])] [UsrStr(0)]  STARS[end]\
MARIO B: [CallLoop(1,'TE_print_star_cnt',3,[1,1,0])] [UsrStr(1)]  STARS[end]\
MARIO C: [CallLoop(1,'TE_print_star_cnt',3,[2,2,0])] [UsrStr(2)]  STARS[end]\
MARIO D: [CallLoop(1,'TE_print_star_cnt',3,[3,3,0])] [UsrStr(3)]  STARS[end]\
BACK[end]\
[DialogResponse(0)][CallOnce(0,'TE_set_state',2,['&copy',0])]\
[DialogResponse(1)][CallOnce(0,'TE_set_state',2,['&copy',1])]\
[DialogResponse(2)][CallOnce(0,'TE_set_state',2,['&copy',2])]\
[DialogResponse(3)][CallOnce(0,'TE_set_state',2,['&copy',3])]\
[DialogResponse(4)][ClearBuffer()][GotoRtrn(0)][end]\
[GenericText()][SetEnv(0,0,0,255)][StartGenBracket(0)][EndDialogBracket(1)]\
\
[copy files is above, choosing files below]\
\
[DialogResponse(0)][CallOnce(0,'TE_set_state',2,['&Op_Type',1])]\
[DialogResponse(1)][CallOnce(0,'TE_set_state',2,['&Op_Type',2])]\
[EndGenBracket(0)][GenericText()][SetEnv(0,0,0,255)][ScaleText(2.0,2.0)][TransOffs(60,0)]CHOOSE FILE\n[ScaleText(1.0,1.0)][TransOffs(30,0)][DialogOptions(4)]\
MARIO A: [CallLoop(1,'TE_print_star_cnt',3,[0,0,0])] [UsrStr(0)]  STARS[end]\
MARIO B: [CallLoop(1,'TE_print_star_cnt',3,[1,1,0])] [UsrStr(1)]  STARS[end]\
MARIO C: [CallLoop(1,'TE_print_star_cnt',3,[2,2,0])] [UsrStr(2)]  STARS[end]\
MARIO D: [CallLoop(1,'TE_print_star_cnt',3,[3,3,0])] [UsrStr(3)]  STARS[end]\
BACK[end]\
[DialogResponse(0)][StartDialogBracket(1)][CallOnce(0,'FS_do_operation',1,[0])][EndDialogBracket(1)]\
[DialogResponse(1)][StartDialogBracket(1)][CallOnce(0,'FS_do_operation',1,[1])][EndDialogBracket(1)]\
[DialogResponse(2)][StartDialogBracket(1)][CallOnce(0,'FS_do_operation',1,[2])][EndDialogBracket(1)]\
[DialogResponse(3)][StartDialogBracket(1)][CallOnce(0,'FS_do_operation',1,[3])][EndDialogBracket(1)]\
[DialogResponse(4)][ClearBuffer()][GotoRtrn(0)][end]\
[GenericText()][CallOnce(3,'TE_get_state',1,['&Op_Type'])][MatchRtrn(3,1)][TimeEndStr(1)][end][GenericText()][ClearBuffer()][GotoRtrn(0)][end]\
"]


DVA_credits = ["[SetEnv(0,0,0,255)][TransOffs(40,0)]\
Levels - scuttlebug_raiser\n\n\
music ports - scuttlebug_raiser\n\n\
tools used:\n\
fast64, decomp\n\n\n\n\
Made for Mario Jams competition\
[AbtnNextBox()][GotoRtrn(0)]"]


#ending

TE_ending = ["[ShadowText(1)][SetSpd(1)][NoFFSpd()][StartTransition(255,0,0,0)][EndTransition(255,0,0,0)][Pause(300)][SetSpd(0)][AutoNextBox()][SetSfx(0x5037)]Wonderful job, Mario my son.\n\
Thanks to you, anime is defeated.[SetSpd(1)][Pause(720)][AutoNextBox()][end]"]