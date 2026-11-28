// rolefeed (3.1 T4): func_800EA8E8 of src/rock_05/E9860.c
// clang-format off

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
extern void (*D_800F3DBC[])(s8*);

void func_800EA8E8(s8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    if (D_80097180 != 2 && is_off_screen(arg0, 0x40, 0xF0) != 1) {
        D_800F3DBC[arg0[4]](arg0);
    }
}
