#include "common.h"
#define M2C_UNK s32

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_800CCEF6;

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_80047460(void* arg0) {

    if (D_800CCEF6 != 0) {
        s32 v;

        func_80029478(0x3C, 2, 2);
        v = F_S32(arg0, 0x18);
        F_S16(arg0, 0x16) = 0x500000 / (v < 0 ? -v : v);
        F_U8(arg0, 5) = 5;
        F_S32(arg0, 0x18) = -0x10000;
        F_U16(arg0, 0x14) = 0x32;
        F_S32(arg0, 0x20) = F_S32(arg0, 0x1C);
        return;
    }
    if (--F_S16(arg0, 0x14) == 0) {
        s32 a;

        a = F_S32(arg0, 0x18);
        F_S16(arg0, 0x16) = 0x500000 / (a < 0 ? -a : a);
        if (a > 0) {
            F_U8(arg0, 5) = 2;
            return;
        }
        F_U8(arg0, 5) = 3;
        func_80016C48(2, 0x22, arg0);
    }
}
