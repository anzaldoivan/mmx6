#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800179A4(void*, s32);
M2C_UNK func_80017A04();

extern s8 D_800970A2;

void func_800EC8BC(struct X4_PlayerObj* self) {
    s8* p;
    // !FAKE: depin: dropping it breaks the match (58/62)
    register s32 m asm("$2");

    p = M2C_FIELD(self, s8**, 0x7C);
    func_80017A04();
    m = M2C_FIELD(self, u8*, 0x45) & 0xF;
    if (m == 1) {
        if (D_800970A2 == 0) {
            if (self->unk2 == 0xE) {
                goto f;
            }
            goto e;
        }
        if (p[0x5C] < 3) {
            if (self->unk2 == 0xE) {
            f:
                ((void (*)(void*, s32))func_800179A4)(self, 0xF);
                M2C_FIELD(self, u8*, 0x86) = 0;
            } else {
            e:
                func_800179A4(self, 0xE);
                M2C_FIELD(self, u8*, 0x86) = 0;
            }
        } else {
            if (self->unk2 == 0xE) {
                func_800179A4(self, 0xA);
            } else {
                func_800179A4(self, 9);
            }
            M2C_FIELD(self, u8*, 0x86) = 1;
        }
        self->unk7++;
    }
}
