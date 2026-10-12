#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
extern M2C_UNK D_800970A0;

void func_80020AA8(struct X4_AnimatedObj* arg0) {
    struct X4_PlayerObj* pl = &D_800970A0;
    s32 var_v1;
    s8 temp_a1;

    temp_a1 = arg0->unk2;
    arg0->x_pos.val = pl->x_pos.val;
    arg0->y_pos.val = pl->y_pos.val;
    if (temp_a1 == 3) {
        if ((pl->unk5 == 0x23) && (pl->unk6 > 0)) {
            arg0->on_screen = 1;
            if (arg0->unk6 != pl->unk6) {
                arg0->unk6 = pl->unk6;
                if (pl->y_vel.val > 0) {
                    func_800179A4(arg0, 0x2B);
                } else if (pl->y_vel.val < 0) {
                    func_800179A4(arg0, 0x2C);
                } else {
                    func_800179A4(arg0, 0x2A);
                }
            }
            arg0->unk15 = pl->unk15;
            func_80017A04(arg0);
            return;
        }
        func_800179A4(arg0, 0x2A);
        {
            register s32 two asm("$2") = 2;
            arg0->unk6 = two;
        }
        arg0->on_screen = 0;
        return;
    }
    if (arg0->state == 0) {
        var_v1 = 1;
        if (temp_a1 == 0) {
            var_v1 = 2;
        }
        if ((pl->charge_state[0] == var_v1) ||
            (pl->charge_state[1] == var_v1)) {
            arg0->on_screen = 1;
            func_800179A4(arg0, temp_a1 + 8);
            {
                register s32 t asm("$2") = (u8)arg0->state + 1;
                arg0->state = t;
            }
        }
    } else {
        if ((pl->charge_state[0] == 0) && (pl->charge_state[1] == 0)) {
            arg0->on_screen = 0;
            arg0->state = 0;
            return;
        }
        func_80017A04(arg0);
    }
}
