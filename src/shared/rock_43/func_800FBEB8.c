#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
extern s32 D_800FE290;
extern s32 D_800FE294;

void func_800FBEB8(struct X4_MainObj* self) {
    if (D_800FE290 != 0 || D_800FE294 != 0) {
        self->state++;
        return;
    }
    switch (self->unk5) {
    case 0:
        if (M2C_FIELD(self, u32*, 0x8C) >= 7) {
            if (func_80031474(self) < 0) {
                self->attack_box = 0;
                self->hurt_box = 0;
                M2C_FIELD(self, u32*, 0x8C) = 0xA;
                self->unk5++;
            } else {
                func_80030ECC(self);
            }
        }
        ((void (*)(void*, s32, s32))func_8002CCB0)(self, 0x20, 0x80);
        if (self->on_screen == 0) {
            self->state++;
        }
        ((void (*)(void*))func_80017A04)(self);
        if (++M2C_FIELD(self, u32*, 0x8C) >= 7) {
            move_object(self);
        }
        break;
    case 1:
        if (++M2C_FIELD(self, u32*, 0x8C) == 0x1E) {
            self->state++;
        }
        if (M2C_FIELD(self, u32*, 0x8C) & 1) {
            func_8002CCB0(self, 0x20, 0x80);
        }
        func_80017A04(self);
        move_object(self);
        break;
    }
}
