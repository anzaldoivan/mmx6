#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
s32 func_80016C48(s32 a0, s32 a1, void* arg2);
void func_8004FE58(s32, s8);

#define ENG ((u8*)&D_800CCED0)
#define ENG5B (((struct X4_EngineObj*)(ENG - -D_800970A0.unk2))->unk5C[-1])

void func_8004ED4C(u8* arg0, u8 arg1, u8 a2) {
    register s32 arg2 asm("$20") = a2;
    u8 hi;
    s8 i;
    u8* p;
    s32 v;
    u8* base;

    hi = (u8)D_800970A0.hp & 0x80;
    if (((u8)D_800970A0.hp & 0x7F) < ENG5B) {
        func_8004FE58(1, ENG5B);
        arg0[0x80] = 4;
        arg0[0x7F] = arg1;
        arg0[4] = 2;
        arg0[5] = 0;
        arg0[6] = 0;
        arg0[0] |= 8;
    } else {
        arg0[4] = 3;
    }
    base = ENG;
    if (((u8)D_800970A0.hp & 0x7F) >= ENG5B) {
        D_800970A0.hp = (u8)ENG5B | hi;
    }
    for (i = 0; i < 2; i++) {
        p = &base[i + 0x63];
        if (*(volatile u16*)(base + 0x6A) & (0x1000 << i)) {
            v = *p & 0x7F;
            if (v < 0x20) {
                register s32 c asm("$3");
                {
                    register s32 t asm("$2") = arg2 + v;
                    v = (s8)t;
                }
                if ((c = v < 0x20, c) == 0) {
                    v = 0x20;
                    func_80016C48(0, 0x18, 0);
                }
                *p = v | 0x80;
                return;
            }
        }
    }
#undef ENG5B
}
