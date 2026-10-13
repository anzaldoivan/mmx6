#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s32 D_801F3A10;
extern s32 D_801F3A14;
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);

void func_801F0D58(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* p = &D_800970A0;

    if (p->unk5 != 0x2C) {
        arg0->state = 2;
        return;
    }
    if (p->unk6 == 2) {
        func_80016C48(1, 0x22, arg0);
        if (p->input.buttons.held & 4) {
            arg0->x_vel.val = 0x8000;
            arg0->y_vel.val = 0x18000;
            arg0->unk2C = 0x800;
        } else {
            arg0->x_vel.val = 0x10000;
            arg0->y_vel.val = 0x10000;
            arg0->unk2C = 0x800;
        }
        if (p->unk15 == 0) {
            arg0->x_vel.val = -arg0->x_vel.val;
        }
        arg0->unk50 = &D_801F3A10;
        M2C_FIELD(arg0, void**, 0x68) = &D_801F3A14;
        arg0->unk5++;
    }
    arg0->x_pos.u.hi = M2C_FIELD(arg0, u16*, 0x8C) + p->x_pos.u.hi;
    arg0->y_pos.u.hi = M2C_FIELD(arg0, u16*, 0x8E) + p->y_pos.u.hi;
}
#undef D_800970A0
