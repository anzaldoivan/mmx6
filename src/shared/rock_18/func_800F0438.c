// rolefeed (3.1 T4): func_800F0438 of src/rock_18/E9860.c
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

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F1024[][3];

void func_800F0438(void* arg0) {
    u8 v;
    u8 b;

    v = M2C_FIELD(arg0, u8*, 0x57);
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (v != 0) {
        if ((v - 1) == D_80097420.transition.selection) {
            M2C_FIELD(arg0, s16*, 0x42) = 0x78C6;
            return;
        }
        b = D_800F1024[M2C_FIELD(arg0, u8*, 2)][1];
        M2C_FIELD(arg0, s16*, 0x42) = (b & 0xF) | (((b >> 4) + 0x1E0) << 6);
    }
}
