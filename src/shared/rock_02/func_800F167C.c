#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s32 D_800FBC70;

void func_800F167C(struct X4_MainObj* arg0) {
    struct X4_MainObj* temp_a1;

    temp_a1 = M2C_FIELD(arg0, struct X4_MainObj**, 0x7C);
    arg0->unk15 = temp_a1->unk15;
    arg0->x_pos.u.hi = temp_a1->x_pos.u.hi;
    arg0->y_pos.u.hi = temp_a1->y_pos.u.hi;
    if (D_800FBC70 != 0) {
        arg0->state = 2;
        return;
    }
    if (temp_a1->unk17 == 0xC) {
        func_8002CCB0(arg0, 0x40, 0x40);
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}
