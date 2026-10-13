#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_800EA858[];
extern s16 D_800EA874[][2];
extern u8 D_800EA8A8[][8];
extern u8 D_800EA9AC[];

#define SCR20 (*(s32**)0x1F800020)
#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_800E9BAC(void* arg0) {
    s32* p;
    s8 kind;
    s8 idx;
    s32 off;

    F(u8, 0x0) = 1;
    F(u16, 0x42) = 0x7800;
    F(u16, 0x40) = 0x1880;
    p = SCR20;
    kind = F(s8, 0x2);
    off = *p;
    F(void*, 0x30) = D_800EA9AC;
    F(s8, 0x14) = -1;
    F(u8, 0x3) = 1;
    F(s32, 0x3C) = (s32)p + off;
    if (kind == 0) {
        func_800179A4(arg0, 0);
        func_80016C48(2, 0x49, 0);
    } else if (kind == 1) {
        func_800179A4(arg0, 1);
        func_80016C48(2, 0x4A, 0);
        idx = F(s8, 0x54);
        func_80027BA0(D_800EA858[idx], D_800EA874[idx][0], D_800EA874[idx][1],
                      D_800EA8A8[idx]);
        D_800971F8[D_800EA858[idx]].unk4C = kind;
    } else {
        func_800179A4(arg0, 2);
        func_80016C48(2, 0x49, 0);
    }
    F(u8, 0x4) = F(u8, 0x4) + 1;
}
