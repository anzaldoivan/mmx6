#include "common.h"
#include "mmx6/x4.h"

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
void func_800FA31C(void* arg0);
extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800FD464[];
extern u8 D_800FDA78[];

#define F856C(o, type, off) (*(type*)((u8*)(o) + (off)))

void func_800F856C(void* arg0) {
    s32 i;

    if (--F856C(arg0, s16, 0x7C) == 0) {
        for (i = 0; i < 0x13; i++) {
            func_80027BA0(0, D_800971F8[0].unk26 + 0x10 + i * 0x10,
                          F856C(arg0, s16, 0xE) & 0xFFF0, D_800FD464);
        }
        D_800FDA78[F856C(arg0, u8, 0x2) & 0xF] = 0;
        F856C(arg0, u8, 0x4) = 6;
        return;
    }
    if (F856C(arg0, s16, 0x7C) & 1) {
        func_800FA31C(arg0);
    }
}
