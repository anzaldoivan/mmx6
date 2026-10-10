#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
extern s8 D_800CCF5C;
#define D_800CCF5C (*(u8*)&D_800CCF5C)

void func_800EFE14(struct X4_MainObj* self) {
    u32 r;
    register s32 v asm("$2");
    register s32 c asm("$2");
    u8 m;

    r = func_8002D2D4() & 0xF;
    m = SCRATCH_4C[0x8B];
    if (m == 2) {
        if ((s8)D_800CCF5C / 2 < self->hp) {
            if (r < 8) {
                self->unk5 = 6;
            } else {
                self->unk5 = 5;
            }
            goto inc;
        }
        c = r < 7;
        if (c == 0) {
            v = 5;
        } else {
            v = 6;
        }
        self->unk5 = v;
        goto chk;
    }
    if (m == 1) {
        c = r < 8;
        if (c == 0) {
            v = 4;
        } else {
            v = 9;
        }
        do {
            self->unk5 = v;
        } while (0);
        if (self->hp < (s8)D_800CCF5C / 2) {
        chk:
            if (SCRATCH_4C[0x89] == 1 && (func_8002D2D4() & 3)) {
                func_800179A4(self, 0);
                {
                    register s32 a asm("$2") = 0x5A;
                    register s32 b asm("$3") = 8;
                    self->unk7C = a;
                    self->unk5 = b;
                }
            }
        }
    inc:
        SCRATCH_4C[0x89]++;
    } else {
        self->unk5 = 3;
        SCRATCH_4C[0x89] = 0;
    }
    if (SCRATCH_4C[0x89] >= 4) {
        self->unk5 = 0xA;
        SCRATCH_4C[0x8B] += 2;
    }
    self->unk6 = 0;
}
#undef D_800CCF5C
