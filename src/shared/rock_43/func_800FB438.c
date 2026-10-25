#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
s32 func_8002D2D4();
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
extern s32 D_800FDE30;
extern s32 D_800FE1F8;
extern s32 D_800FE1FC;
extern s32 D_800FE290;
extern s32 D_800FE294;

void func_800FB438(struct X4_MainObj* self) {
    if (D_800FE290 != 0 || D_800FE294 != 0) {
        self->state++;
        return;
    }
    if (func_80031474(self) < 0) {
        func_80049E50(self);
        self->state++;
        return;
    }
    func_80030ECC(self);
    switch (self->unk5) {
    case 0:
        self->attack_box = (u8*)&D_800FDE30 + 0x3C4;
        if (++M2C_FIELD(self, s32*, 0x8C) == 3) {
            if (self->unk2 == 1) {
                if (self->unk15 == 0) {
                    self->x_speed = -0x40000;
                } else {
                    self->x_speed = 0x40000;
                }
            } else {
                s16 t;
                s16 a;
                t = func_8002D2D4() % 3 - 1;
                if (self->unk15 == 0) {
                    a = t * 128 + 0x800;
                } else {
                    a = t * 128;
                }
                self->x_speed = func_80065A14(a) << 6;
                self->y_speed = -func_80065944(a) << 6;
            }
            self->unk5++;
        }
        break;
    case 1:
        if (++M2C_FIELD(self, s32*, 0x8C) == 0xC) {
            func_800179A4(self, 0xA);
            {
                // !FAKE: depin: dropping it breaks the match (137/141)
                register void* a asm("$2") = &D_800FE1F8;
                // !FAKE: depin: dropping it breaks the match (99/141)
                register void* b asm("$3") = &D_800FE1FC;
                self->attack_box = a;
                self->hurt_box = b;
            }
            M2C_FIELD(self, s32*, 0x8C) = 0;
            self->unk5++;
        }
        break;
    case 2:
        if (++M2C_FIELD(self, s32*, 0x8C) == 0x64) {
            self->state++;
        }
        func_8002CCB0(self, 0x30, 0x20);
        break;
    }
    func_80017A04(self);
    move_object(self);
}
