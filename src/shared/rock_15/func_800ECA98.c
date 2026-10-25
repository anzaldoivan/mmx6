#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800F622C[];
extern s32 D_800F6234[];

#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800ECA98(struct X4_MainObj* self) {
    u8 t;
    s32 c;
    s32 y;
    s32* q;

    t = U8F(self, 0x8F);
    if (t == 0) {
        q = D_800F622C;
        self->x_speed = *(s32*)(((self->unk15 >> 4) & 4) + (u8*)q);
        y = D_800F6234[self->unk2 != 0];
        self->unk42 &= 0x7FFF;
        self->unk5++;
        self->y_speed = y;
        return;
    }
    U8F(self, 0x8F) = t - 1;
    c = U8F(self, 0x90) - 1;
    U8F(self, 0x90) = c;
    if ((c & 0xFF) == 0xFF) {
        U8F(self, 0x90) = 2;
        self->unk42 &= 0x7FFF;
        return;
    }
    self->unk42 |= 0x8000;
}
#undef U8F
