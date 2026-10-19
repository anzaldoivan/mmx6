#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_80042C18(struct X4_MainObj* self);
extern u8 D_800CCF38;

void func_800420CC(struct X4_MainObj* self) {
    s32 d;
    s32 var_v0;
    // !FAKE: retail keeps the second stored value in the second return register
    register s32 var_v1 asm("$3");

    func_80042C18(self);
    ((void (*)(void*, M2C_UNK))func_800179A4)(self, 4);
    d = D_800CCF38;
    {
        s32 one = 1;
        if (d != one) {
            if (d < 2) {
                var_v0 = 0x1E;
                var_v1 = 5;
                if (d == 0) {
                    var_v0 = 0x5A;
                    var_v1 = 3;
                }
            } else {
                // !FAKE: places the two-or-more arm after the equals-one arm
                goto block_a3;
            }
        } else {
            var_v0 = 0x3C;
            var_v1 = 4;
        }
    }
    if (0) {
    block_a3:
        var_v0 = 0x1E;
        var_v1 = 5;
    }
    self->unk7C = var_v0;
    self->unk7E = var_v1;
    do {
    } while (0);
    self->unk6++;
}
