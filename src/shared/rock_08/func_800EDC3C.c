#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80031DA8();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK D_800F5AA4;
extern void (*D_800F5AB8[])(struct X4_PlayerObj*);

void func_800EDC3C(struct X4_PlayerObj* self) {
    s8 hp;
    s8 kind;

    hp = self->hp;
    if (check_enemy_hits(self) < 0) {
        kind = self->unk2;
        if (kind == 3 || kind == 6) {
            func_800477E4(6, &D_800F5AA4, self);
            func_80049EBC(self, 1, 0x20, 0x30);
            func_80049EBC(self, 1, 0x20, 0x30);
            func_80049EBC(self, 1, 0x20, 0x30);
        } else if (kind == 4) {
            func_800477E4(6, &D_800F5AA4, self);
            func_80049EBC(self, 1, 0x10, 0x20);
            func_80049EBC(self, 1, 0x10, 0x20);
            func_80049EBC(self, 1, 0x10, 0x20);
        } else {
            func_800477E4(6, &D_800F5AA4, self);
            func_80049EBC(self, 1, 0x20, 0x10);
            func_80049EBC(self, 1, 0x20, 0x10);
            func_80049EBC(self, 1, 0x20, 0x10);
        }
        self->state = 2;
        return;
    }
    func_80030ECC(self);
    if (self->hp != hp) {
        self->unk42 |= 0x8000;
    }
    D_800F5AB8[self->unk6](self);
    func_80017A04(self);
    func_80031DA8(self);
    if (self->on_screen != 0) {
        func_80031F4C(self);
    }
    if (func_8002CBFC(self, 0x30, 0x30) == 0) {
        func_8002CCB0(self, 0x30, 0x30);
    }
}
