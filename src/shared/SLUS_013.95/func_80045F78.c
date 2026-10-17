#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
s32 func_8003EB0C(void* arg0, s32 arg1);
extern struct X4_PlayerObj D_800970A0;

#define F5F78(p, t, o) (*(t*)((u8*)(p) + (o)))

void func_80045F78(void* arg0) {
    struct X4_PlayerObj* p = &D_800970A0;
    s32 hit = 0;
    s32 v;

    if (p->unk2 != 0) {
        s16 w = F5F78(p, s16, 0xB0);

        hit = w < func_8003EB0C(p, 4);
    } else {
        v = ((s16*)((u8*)&D_800970A0 + 0xA8))[p->weapon];
        v = v < func_8003EB0C(p, p->weapon);
        if (v) {
            hit = 1;
        }
    }
    if (p->unk2 == 0 && (F5F78(p, u16, 0x80) & 0x10)) {
        hit = 1;
    }
    if (hit != 0) {
        func_80016C48(1, 0x1D, arg0);
        F5F78(arg0, u8, 0x8D) = 1;
        F5F78(arg0, u8, 0x4) = 3;
    }
}

#undef F5F78
