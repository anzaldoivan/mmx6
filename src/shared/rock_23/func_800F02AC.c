#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
#define move_object ((void (*)(void*))move_object)
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);

void func_800F02AC(struct X4_PlayerObj* self) {
    func_80017A04();
    move_object(self);
    self->unk42 &= 0x7FFF;

    if (func_80030ECC(self) != 0) {
        if (self->unk2 != 0) {
            func_80049E50(self);
        } else {
            func_80049D90(self);
        }
        self->state = 2;
        return;
    }
    if (self->unk2 != 0 && check_enemy_hits(self) < 0) {
        func_80049E50(self);
        self->state = 2;
        return;
    }
    if (self->unk70 != 0 || (func_8002EE10(self), self->unk70 != 0)) {
        if (self->unk2 != 0) {
            func_80049E50(self);
        } else {
            func_80049D90(self);
        }
        self->state = 2;
        return;
    }
    if (func_8002CBFC(self, 0x20, 0x20) == 0) {
        func_8002CCB0((struct X4_BaseObj*)self, 0x10, 0x10);
        return;
    }
    self->state = 2;
}
#undef move_object
