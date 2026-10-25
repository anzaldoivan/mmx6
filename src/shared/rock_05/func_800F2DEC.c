#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F2DEC(struct X4_MainObj* self) {
    u8* s1;

    s1 = *(u8**)&self->unk7C;
    ((M2C_UNK(*)())func_80017A04)();
    {
        // !FAKE: depin: dropping it breaks the match (33/38)
        register s32 t asm("$2") = (u8)self->unk7 - 1;
        self->unk7 = t;
    }
    if (!(self->unk7 & 1)) {
        self->unk42 |= 0x8000;
    } else {
        self->unk42 &= 0x7FFF;
    }
    func_8002CCB0(self, 0x30, 0x30);
    {
        // !FAKE: depin: dropping it breaks the match (36/38)
        register s32 c asm("$2") = self->unk7;
        if (c == 0) {
            self->state = 2;
            s1[0x94] = 1;
        }
    }
}
