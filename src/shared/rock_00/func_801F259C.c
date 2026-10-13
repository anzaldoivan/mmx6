#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void func_8002D2B0(struct X4_MovingObj*);
void func_8002F06C(void*);
void* func_8003D480(M2C_UNK, s8, s8, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)

void func_801F259C(struct X4_WeaponObj* arg0) {
    s32 mask;
    register s32 t asm("$3");

    func_80017A04(ANIMATED_OBJECT(arg0));
    func_8002D2B0(MOVING_OBJECT(arg0));
    mask = 8;
    if (arg0->y_vel.val > 0) {
        mask = 4;
    }
    func_8002F06C(arg0);
    t = arg0->unk70 & mask;
    if (t) {
        arg0->unk50 = 0;
        arg0->unk68 = 0;
        if (arg0->y_vel.val > 0) {
            if (func_8003D480(arg0->active, arg0->id, 2, arg0) != 0) {
                arg0->unk7++;
            }
            func_800179A4(arg0, 2);
        } else {
            if (func_8003D480(arg0->active, arg0->id, 3, arg0) != 0) {
                arg0->unk7++;
            }
            func_800179A4(arg0, 3);
        }
        arg0->state = 2;
    } else {
        func_8002CCB0(arg0, 0x20, 0x20);
        if (arg0->on_screen == 0) {
            arg0->state = 3;
            arg0->unk50 = 0;
            arg0->unk68 = 0;
        }
    }
}
#undef func_800179A4
#undef func_8002CCB0
