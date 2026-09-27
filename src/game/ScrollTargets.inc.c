#include <PR/ultratypes.h>
#include "sm64.h"
#include "types.h"

//Q. Why does this exist instead of just directly referencing VBs?
//A. Because gcc is dumb and will seg fault if you reference a VB by abstracting it through a bparam
//instead of directly refencing it, causing this horrible shit.
extern Vtx VB_hmc_1_0xe020d90[];
extern Vtx VB_jrb_1_0xe02a450[];
extern Vtx VB_castle_grounds_1_0xe021d50[];
extern Vtx VB_castle_grounds_1_0xe0315a0[];
extern Vtx VB_castle_grounds_1_0xe0319c0[];
extern Vtx VB_bitdw_1_0xe018e10[];
extern Vtx VB_bitdw_2_0xe020810[];
extern Vtx VB_bitdw_2_0xe00b8e0[];
extern Vtx VB_wf_1_0xe005270[];
extern Vtx VB_wf_1_0xe005810[];
extern Vtx VB_wf_1_0xe00c970[];
extern Vtx VB_wf_1_0xe00cbb0[];
extern Vtx VB_wf_1_0xe00dcd0[];
extern Vtx VB_wf_1_0xe00f160[];
extern Vtx VB_wf_1_0xe00faf0[];
extern Vtx VB_wf_1_0xe0103b0[];
extern Vtx VB_wf_1_0xe0103f0[];
extern Vtx VB_wf_1_0xe013750[];
extern Vtx VB_wf_1_0xe015360[];
extern Vtx VB_wf_1_0xe015d50[];
extern Vtx VB_wf_1_0xe016710[];
extern Vtx VB_wf_1_0xe016b70[];
extern Vtx VB_wf_1_0xe016e30[];
extern Vtx VB_wf_1_0xe017bd0[];
extern Vtx VB_wf_1_0xe017e10[];
extern Vtx VB_wf_1_0xe0186f0[];
extern Vtx VB_wf_1_0xe01ad50[];
extern Vtx VB_wf_1_0xe01ae70[];
extern Vtx VB_wf_1_0xe01bf90[];
extern Vtx VB_cotmc_1_0xe007070[];
extern Vtx VB_cotmc_1_0xe00d090[];
extern Vtx VB_totwc_1_0xe007120[];
extern Vtx VB_totwc_1_0xe008420[];
extern Vtx VB_totwc_1_0xe008e40[];
extern Vtx VB_totwc_1_0xe009860[];
Vtx *ScrollTargets[]={
 &VB_hmc_1_0xe020d90[0],
 &VB_jrb_1_0xe02a450[0],
 &VB_castle_grounds_1_0xe021d50[0],
 &VB_castle_grounds_1_0xe0315a0[0],
 &VB_castle_grounds_1_0xe0319c0[0],
 &VB_bitdw_1_0xe018e10[0],
 &VB_bitdw_2_0xe020810[0],
 &VB_bitdw_2_0xe00b8e0[0],
 &VB_wf_1_0xe005270[0],
 &VB_wf_1_0xe005810[0],
 &VB_wf_1_0xe00c970[0],
 &VB_wf_1_0xe00cbb0[0],
 &VB_wf_1_0xe00dcd0[0],
 &VB_wf_1_0xe00f160[0],
 &VB_wf_1_0xe00faf0[0],
 &VB_wf_1_0xe0103b0[0],
 &VB_wf_1_0xe0103f0[0],
 &VB_wf_1_0xe013750[0],
 &VB_wf_1_0xe015360[0],
 &VB_wf_1_0xe015d50[0],
 &VB_wf_1_0xe016710[0],
 &VB_wf_1_0xe016b70[0],
 &VB_wf_1_0xe016e30[0],
 &VB_wf_1_0xe017bd0[0],
 &VB_wf_1_0xe017e10[0],
 &VB_wf_1_0xe0186f0[0],
 &VB_wf_1_0xe01ad50[0],
 &VB_wf_1_0xe01ae70[0],
 &VB_wf_1_0xe01bf90[0],
 &VB_cotmc_1_0xe007070[0],
 &VB_cotmc_1_0xe00d090[0],
 &VB_totwc_1_0xe007120[0],
 &VB_totwc_1_0xe008420[0],
 &VB_totwc_1_0xe008e40[0],
 &VB_totwc_1_0xe009860[0],
};