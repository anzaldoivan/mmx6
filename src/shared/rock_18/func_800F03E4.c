// rolefeed (3.1 T4): func_800F03E4 of src/rock_18/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_800139A0(M2C_UNK);
M2C_UNK reset_level();
void func_800EA3F0(s32, s32, s32, s32);
void func_800EA470(s32, s32, s32, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"

// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800F10F8[][2];

void func_800F03E4(void* arg0) {
    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, u16*, 0xA) =
        D_800F10F8[(u8)D_80097420.transition.selection][0];
    M2C_FIELD(arg0, s16*, 0xE) =
        D_800F10F8[(u8)D_80097420.transition.selection][1] - 3;
}
