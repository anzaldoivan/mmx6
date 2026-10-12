#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))

s32 func_800179A4(void*, s32);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(s32);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj D_800970A0;

void func_800ECBC4(struct X4_MainObj* self) {
    s32 a;

    func_80017A04();
    {
        register s32 t asm("$2") = OH(self, 0x80);
        if (t == 0) {
            goto ready;
        }
    }
    {
        OH(self, 0x80)--;
        func_8002D230((s32)self);
        return;
    }
ready:
    OH(self, 0x82) = D_800970A0.x_pos.i.hi;
    OH(self, 0x84) = D_800970A0.y_pos.i.hi;
    func_800179A4(self, 0x11);
    {
        u16 x = D_800970A0.x_pos.i.hi;
        u16 y;
        OH(self, 0x82) = x;
        y = D_800970A0.y_pos.i.hi;
        OH(self, 0x84) = y;
        a = func_80065B74((s16)y - self->y_pos.i.hi, (s16)x - self->x_pos.i.hi);
    }
    OW(self, 0x20) = func_80065A14(a) << 5;
    OW(self, 0x24) = -func_80065944(a) << 5;
    self->unk7++;
}
