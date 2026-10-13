#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800F7694;
extern s32 D_800F7700;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EE080(void* arg0) {
    u16 t;

    if (!(FU16(arg0, 0x8C) & 1)) {
        FU16(arg0, 0x42) ^= 0x8000;
    }
    t = FU16(arg0, 0x8C);
    FU16(arg0, 0x8C) = t + 1;
    if ((s16)t >= 0x33) {
        F32(arg0, 0x50) = (s32)&D_800F7700;
        F32(arg0, 0x54) = 0;
        func_800477E4(2, &D_800F7694, arg0);
        ((void (*)(void*))func_80049E50)(arg0);
        F8(arg0, 4) = 2;
    }
}
