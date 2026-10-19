#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_8003C4EC(struct X4_PlayerObj* self);
M2C_UNK func_8003CD9C();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
s32 func_8003EB0C(void* arg0, s32 arg1);
void func_8003F740(void*, s32);
M2C_UNK func_801EC614();
extern s8 D_800CCEEC;

s32 func_801EA680(u8* arg0) {
    if (*(s8*)(arg0 + 0xD3) == 0 && (arg0[0xC9] & 0x80)) {
        s32 t;
        if (!(*(u16*)(arg0 + 0x80) & 0x40)) {
            return 0;
        }
        t = func_8003EB0C(arg0, 5);
        if (*(s16*)(arg0 + 0xB2) < t) {
            return 0;
        }
        if (*(s8*)(arg0 + 0x8E) == 0) {
            arg0[0x93] = 5;
            arg0[0xDD] = 1;
            arg0[0x8E] = 1;
            arg0[0xCB] = 0;
            arg0[0x8C] = 0;
            func_8003CD9C(arg0);
            func_8003BA04(arg0, 0x68);
            func_8003CFE0(arg0, 7);
            arg0[0x61] = 0;
            arg0[0xA4] = 0;
            func_8003C4EC((struct X4_PlayerObj*)arg0);
            arg0[0xE0] = 2;
            arg0[0xE1] = 0;
            *(s32*)(arg0 + 0x68) = 0;
            arg0[0x67] = 1;
            arg0[0x7A] = 1;
            D_800CCEEC = 1;
            func_8003F740(arg0, *(s8*)(arg0 + 0x93));
            arg0[5] = 0x3B;
            arg0[6] = 0;
            arg0[7] = 0;
            func_801EC614(arg0);
            return 1;
        }
    }
    return 0;
}
