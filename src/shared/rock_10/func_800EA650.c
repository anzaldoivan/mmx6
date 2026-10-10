#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern s16 D_8009721C;
extern s16 D_80097220;
extern u8 D_800FA900[];

void func_800EA650(struct X4_AnimatedObj* self) {
    ((void (*)(struct X4_AnimatedObj*))func_80017A04)(self);
    if (self->animation_step.fields.event != 1) {
        return;
    }
    switch (self->unk2 & 0xF) {
    case 0:
        D_8009721C = 0xDA0;
        func_80027BA0(0, 0xC40, 0x150, D_800FA900 + 0x1590);
        break;
    case 1:
        D_8009721C = 0xEF0;
        func_80027BA0(0, 0xED0, 0x180, D_800FA900 + 0x1598);
        break;
    case 2:
        D_8009721C = 0x1180;
        func_80027BA0(0, 0x1020, 0x150, D_800FA900 + 0x15A0);
        break;
    case 3:
        D_8009721C = 0x12E0;
        func_80027BA0(0, 0x12B0, 0x160, D_800FA900 + 0x15A8);
        break;
    case 4:
        D_80097220 = 0x200;
        func_80027BA0(0, 0x1250, 0x1C0, D_800FA900 + 0x15B0);
        break;
    case 5:
        D_80097220 = 0x300;
        func_80027BA0(0, 0xF30, 0x2C0, D_800FA900 + 0x15B8);
        break;
    }
    self->unk6++;
}
