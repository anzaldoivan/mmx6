#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s8 D_8009711A;
extern s32 D_800FBC70;

void func_800EE6D0(void* arg0) {
    s8 state;

    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x41) {
        M2C_FIELD(arg0, u8*, 0x5C) -= 8;
        if ((s8)M2C_FIELD(arg0, u8*, 0x5C) <= 0) {
            M2C_FIELD(arg0, u8*, 4) = 2;
            M2C_FIELD(arg0, u8*, 0x5C) = 0;
            M2C_FIELD(arg0, u8*, 5) = 0;
            M2C_FIELD(arg0, u8*, 6) = 0;
            D_800FBC70 = 1;
            D_8009711A = 1;
            func_8002CCB0(arg0, 0xA0, 0xA0);
            return;
        }
    }
    state = M2C_FIELD(arg0, s8*, 7);
    if (state != 0) {
        if (state == 1) {
            s32 idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
            s32 base = SPAD20;
            // !FAKE: depin: dropping it breaks the match (46/73)
            register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);
            M2C_FIELD(arg0, s32*, 0x3C) = base + off;
            ((void (*)(void*, s32, s32))func_800179A4)(arg0, 9, off);
            M2C_FIELD(arg0, u8*, 7)++;
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            func_80016C48(2, 4, arg0);
            M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}
