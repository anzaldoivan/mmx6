#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern s16 D_800F6BEA;
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;
void func_800F49C8(struct X4_MainObj* arg0) {
    struct X4_MainObj* self;

    if (D_800F6BF8 != 0 || D_800F6BFC != 0) {
        self = arg0;
        goto inc;
    }
    self = arg0;
    if (check_enemy_hits(self) < 0 || D_800F6BEA + 0x40 < self->y_pos.i.hi ||
        func_80030ECC(self) != 0) {
    inc:
        self->state++;
        return;
    }
    func_8002CCB0(self, 0x20, 0x20);
    func_80017A04(self);
    func_8002D230(self);
}
