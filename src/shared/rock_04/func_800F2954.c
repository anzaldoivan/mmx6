#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK D_800F76B8;

void func_800F2954(struct X4_BaseObj* self) {
    s8 st;

    st = M2C_FIELD(self, struct X4_BaseObj**, 0x7C)->state;
    if (st != 1) {
        self->state = 2;
        goto end;
    }
    M2C_FIELD(self, s32*, 0x18) = M2C_FIELD(self, s32*, 0x8);
    M2C_FIELD(self, s32*, 0x1C) = M2C_FIELD(self, s32*, 0xC);
    func_80017A04(self);
    ((void (**)(struct X4_BaseObj*)) & D_800F76B8)[self->unk5](self);
    if (self->state != st) {
        goto end;
    }
    if (check_enemy_hits(self) < 0) {
        if (!(self->unk2 & 0xF0)) {
            play_sound(2, 0x17, self);
            func_80012D9C(8);
        }
        goto kill;
    }
    if (func_80030ECC(self) != 0) {
        switch (self->unk2 & 0xF0) {
        case 0:
            play_sound(2, 0x17, self);
            func_80012D9C(8);
        case 0x10:
        kill:
            self->on_screen = 0;
            func_80049E50(self);
            self->state = 2;
            return;
        }
    }
    if (func_8002CBFC(self, 0x20, 0x50) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
    } else {
        self->state = 2;
    }
    if ((self->unk2 & 0xF0) != 0x20) {
        return;
    }
end:
    self->on_screen = 0;
}
