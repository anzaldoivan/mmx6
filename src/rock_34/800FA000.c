// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", D_800FA000);

#define init_wolfang_ice_spike func_800FA008
#define D_800F70B0 D_800FE7A8
#define D_800F70B4 D_800FE7AC
#define D_800F70B8 D_800FE7B0
#define D_800F7478 D_800FEB70
#define D_800F7840 D_800FEDE4
#include "../rock_04/wolfang_ice_spike.c"
#undef init_wolfang_ice_spike
#undef D_800F70B0
#undef D_800F70B4
#undef D_800F70B8
#undef D_800F7478
#undef D_800F7840

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FA290);

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FA41C);
// clang-format on

#define func_800F19EC func_800FA544
#include "../shared/rock_04/func_800F19EC.c"
#undef func_800F19EC

#define func_800F1B50 func_800FA6A8
#define background_objects background_objects
#include "../shared/rock_04/func_800F1B50.c"
#undef func_800F1B50
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FA848);
// clang-format on

#define func_800F1EB0 func_800FAA08
#include "../shared/rock_04/func_800F1EB0.c"
#undef func_800F1EB0

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FAB38);

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FAC18);

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FAD40);
// clang-format on

#define func_800F232C func_800FAE84
#define D_800E9B2C D_800FA004
#include "../shared/rock_04/func_800F232C.c"
#undef func_800F232C
#undef D_800E9B2C

// clang-format off
#define func_800F2464 func_800FAFBC
#define D_800F70DC D_800FE7D4
#define func_800F51F0 func_800FDD48
#include "../shared/rock_04/func_800F2464.c"
#undef func_800F2464
#undef D_800F70DC
#undef func_800F51F0

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FB0F8);

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FB2A8);
// clang-format on

#define func_800F2954 func_800FB4AC
#define D_800F76B8 D_800FEDB0
#include "../shared/rock_04/func_800F2954.c"
#undef func_800F2954
#undef D_800F76B8

// clang-format off
INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FB62C);

INCLUDE_ASM("asm/rock_34/nonmatchings/FA000", func_800FB81C);
// clang-format on
