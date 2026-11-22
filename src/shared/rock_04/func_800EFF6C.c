// rolefeed (3.1 T4): func_800EFF6C of src/rock_04/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj g_Player;
extern s32 D_800F6720;
extern s32 D_800F6724;
extern s32 D_800F6728;
extern s32 D_800F6A00;

#include "common.h"

extern s32 D_800F6D90;
extern s32 D_800F6D9C;

void func_800EFF6C(u8* arg0) {
    arg0[3] ^= 1;
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(s32**)(arg0 + 0x54) = &D_800F6D9C;
        *(s32**)(arg0 + 0x50) = &D_800F6D90;
        arg0[6]++;
    }
}
