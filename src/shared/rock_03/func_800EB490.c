#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
void func_800EBC20(struct X4_MainObj* self);
extern void (*D_800F7264[])(struct X4_MainObj*);

void func_800EB490(struct X4_MainObj* self) {
    s8 st;

    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    if (self->unk5 != 5) {
        func_800EBC20(self);
    }
    func_80017A04(self);
    {
        // !FAKE: depin: dropping it breaks the match (53/59)
        register void** tbl asm("$2") = (void**)D_800F7264;
        // !FAKE: depin: dropping it breaks the match (57/59)
        register void* fn asm("$5") = tbl[self->unk5];
        ((void (*)(struct X4_MainObj*))fn)(self);
    }
    if (check_enemy_hits(self) < 0) {
        func_80049E50(self);
        func_8004E654((struct X4_BaseObj*)self, 0x12);
        st = 2;
    } else {
        func_80030ECC(self);
        if (func_8002CBFC((s32)self, 0x50, 0xA0) == 0) {
            if (self->unk5 != 5) {
                func_8002CCB0(self, 0x30, 0x40);
            }
            return;
        }
        st = 3;
    }
    self->state = st;
}
