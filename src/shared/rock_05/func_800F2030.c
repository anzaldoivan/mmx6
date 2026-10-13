#include "common.h"
#define M2C_UNK s32

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
extern s16 D_800F4480;

#define SETB                                                                   \
    {                                                                          \
        S16(arg0, 0xE) = D_800F4480 + 0x438;                                   \
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);                        \
        S16(arg0, 0x7C) = 0x32;                                                \
        F8(arg0, 6)++;                                                         \
        return;                                                                \
    }

void func_800F2030(void* arg0) {
    if (F32(arg0, 0x24) == 0x50000) {
        if (S16(arg0, 0xE) <= D_800F4480 + 0x438) {
            SETB
        }
    } else if (S16(arg0, 0xE) >= D_800F4480 + 0x438) {
        SETB
    }
    func_8002D2B0(arg0);
    func_80017A04(arg0);
}
#undef SETB
