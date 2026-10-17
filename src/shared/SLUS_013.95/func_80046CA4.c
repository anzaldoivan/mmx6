#include "common.h"
#define M2C_UNK s32

s32 func_8002CB50(struct X4_BaseObj*); /* extern */

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define SCRATCH_3C (*(u8**)0x1F80003C)

void func_80046CA4(void* arg0) {
    u8* q;
    s32 t;

    F8(arg0, 0x14) = -1;
    if (F8(arg0, 2) == -1) {
        F16(arg0, 0x40) = 0x1E00;
        q = SCRATCH_3C;
        t = *(s32*)q;
        F16(arg0, 0x42) = 0x7E10;
        F8(arg0, 0x16) = 7;
        F8(arg0, 3) = 1;
        F8(arg0, 4) = 2;
        q += t;
        F32(arg0, 0x3C) = (s32)q;
    } else {
        u8* p;
        F16(arg0, 0x40) = 0x1F00;
        p = SCRATCH_3C;
        F32(arg0, 0x3C) = (s32)(p + *(s32*)(p + 4));
        if (F16(arg0, 0xE) == 0x10) {
            F16(arg0, 0x42) = 0x7C11;
        } else {
            F16(arg0, 0x42) = 0x7C10;
        }
        F16(arg0, 0xA) = 0xA0;
        F8(arg0, 0x16) = 0;
        F8(arg0, 0x47) = F8(arg0, 2);
        F8(arg0, 4) = F8(arg0, 4) + 1;
        func_8002CB50(arg0);
    }
}
