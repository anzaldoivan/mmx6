#include "common.h"
#define M2C_UNK s32

s32 func_8002CB50(struct X4_BaseObj*); /* extern */

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define SCRATCH_3C (*(u8**)0x1F80003C)

void func_800489C0(void* arg0) {
    u8* p;

    F16(arg0, 0x40) = 0x1F00;
    p = SCRATCH_3C;
    p += *(s32*)(p + 4);
    F8(arg0, 0x14) = -1;
    F8(arg0, 0x15) = 0;
    F32(arg0, 0x3C) = (s32)p;
    if (F16(arg0, 0xE) == 0x10) {
        F16(arg0, 0xE) = 0x30;
        F16(arg0, 0x42) = 0x7C11;
    } else {
        F16(arg0, 0x42) = 0x7C10;
    }
    F8(arg0, 0x16) = 0;
    F8(arg0, 4) = F8(arg0, 4) + 1;
    F8(arg0, 0x47) = F8(arg0, 2);
    func_8002CB50(arg0);
}
