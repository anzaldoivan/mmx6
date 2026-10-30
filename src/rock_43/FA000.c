#include "common.h"

INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", D_800FA00C);

#include "../shared/rock_43/func_800FA054.c"

#include "../shared/rock_43/func_800FA2F4.c"

#include "../shared/rock_43/func_800FA52C.c"

#include "../shared/rock_43/func_800FA650.c"

#include "../shared/rock_43/func_800FA8B4.c"

#include "../shared/rock_43/func_800FAADC.c"

#include "../shared/rock_43/func_800FACFC.c"

#include "../shared/rock_43/func_800FAE98.c"

INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", func_800FB0E8);

#include "../shared/rock_43/func_800FB1F0.c"

INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", func_800FB328);

#include "../shared/rock_43/func_800FB438.c"

#include "../shared/rock_43/func_800FB66C.c"

#include "../shared/rock_43/func_800FB764.c"

INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", func_800FB964);

#include "../shared/rock_43/func_800FBB70.c"

#include "../shared/rock_43/func_800FBD38.c"

#include "../shared/rock_43/func_800FBEB8.c"

#include "../shared/rock_43/func_800FC02C.c"

// 0x800FC128 update_nightmare_zero: per-frame state dispatch of the Nightmare Zero boss.
// basis: community refs/leads/tweaks/BossHealth.tsv:2571 (datum 0x800FA000 read via D_800FE134[0])
// callers: none known (object type table)
#define func_800EB5A0 update_nightmare_zero
#define D_800F6A84 D_800FE134
#include "../shared/rock_04/func_800EB5A0.c"
#undef func_800EB5A0
#undef D_800F6A84

#include "../shared/rock_43/func_800FC188.c"

#define func_8003744C func_800FC190
#define D_80073C1C D_800FE174
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_43/func_800FC1CC.c"

#include "../shared/rock_43/func_800FC28C.c"

#include "../shared/rock_43/func_800FC340.c"

#define func_800F4588 func_800FC3B0
#include "../shared/rock_03/func_800F4588.c"
#undef func_800F4588

#define func_800F4674 func_800FC49C
#define D_800F7C30 D_800FE188
#include "../shared/rock_03/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#include "../shared/rock_43/func_800FC500.c"

#define func_8003744C func_800FC508
#define D_80073C1C D_800FE18C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_43/func_800FC544.c"

#include "../shared/rock_43/func_800FC5C8.c"

#include "../shared/rock_43/func_800FC6B0.c"

#include "../shared/rock_43/func_800FC76C.c"

#define func_8003744C func_800FC800
#define D_80073C1C D_800FE19C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_43/func_800FC83C.c"

#include "../shared/rock_43/func_800FC8BC.c"

#include "../shared/rock_43/func_800FC920.c"

#include "../shared/rock_43/func_800FC980.c"

#include "../shared/rock_43/func_800FCA6C.c"

#include "../shared/rock_43/func_800FCB58.c"

#define func_8003744C func_800FCC18
#define D_80073C1C D_800FE1B4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_43/func_800FCC54.c"

#include "../shared/rock_43/func_800FCCD0.c"

#include "../shared/rock_43/func_800FCD30.c"

#define func_800FC76C func_800FCE54
#include "../shared/rock_43/func_800FC76C.c"
#undef func_800FC76C

#define func_800F4674 func_800FCEE8
#define D_800F7C30 D_800FE1C4
#include "../shared/rock_03/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#include "../shared/rock_43/func_800FCF4C.c"

#include "../shared/rock_43/func_800FCFB8.c"

#define func_800F4674 func_800FD0BC
#define D_800F7C30 D_800FE1CC
#include "../shared/rock_03/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#include "../shared/rock_43/func_800FD120.c"

#include "../shared/rock_43/func_800FD17C.c"

#define func_8003744C func_800FD264
#define D_80073C1C D_800FE1D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800FC83C func_800FD2A0
#include "../shared/rock_43/func_800FC83C.c"
#undef func_800FC83C

#include "../shared/rock_43/func_800FD320.c"

#include "../shared/rock_43/func_800FD374.c"

#define func_80041AB8 func_800FD3EC
#define D_80075FD8 D_800FE1E8
#define FAMILY_FIELD 5
#include "../shared/SLUS_013.95/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "../shared/rock_43/func_800FD428.c"

#define func_800F5564 func_800FD4B0
#include "../shared/rock_03/func_800F5564.c"
#undef func_800F5564

#include "../shared/rock_43/func_800FD5B0.c"

#include "../shared/rock_43/func_800FD664.c"

#include "../shared/rock_43/func_800FD6F0.c"

#include "../shared/rock_43/func_800FD710.c"

#include "../shared/rock_43/func_800FD730.c"

#include "../shared/rock_43/func_800FD7C4.c"

#include "../shared/rock_43/func_800FD7E4.c"

#include "../shared/rock_43/func_800FD8D4.c"

#include "../shared/rock_43/func_800FD8F4.c"

#include "../shared/rock_43/func_800FD914.c"

#include "../shared/rock_43/func_800FD9D8.c"

#include "../shared/rock_43/func_800FDA6C.c"

#include "../shared/rock_43/func_800FDA8C.c"

#include "../shared/rock_43/func_800FDAAC.c"

#include "../shared/rock_43/func_800FDB44.c"

#include "../shared/rock_43/func_800FDB64.c"

#include "../shared/rock_43/func_800FDC6C.c"

#include "../shared/rock_43/func_800FDCD4.c"

#include "../shared/rock_43/func_800FDD84.c"

INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", D_800FDE30);
