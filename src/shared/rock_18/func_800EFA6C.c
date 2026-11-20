// rolefeed (3.1 T4): func_800EFA6C of src/rock_18/E9860.c
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

#include "common.h"

extern u8 D_800F0C04[][3];

void func_800EFA6C(u8* arg0) {
    u8 v;
    u8 w;

    v = arg0[0x57];
    arg0[3] = 1;
    if (v != 0) {
        if ((v - 1) == D_80097420.transition.selection) {
            *(s16*)(arg0 + 0x42) = 0x784C;
            return;
        }
        w = D_800F0C04[arg0[2]][1];
        *(s16*)(arg0 + 0x42) = (w & 0xF) | (((w >> 4) + 0x1E0) << 6);
    }
}
