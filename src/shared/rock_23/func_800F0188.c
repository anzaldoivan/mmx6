#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230();
extern s32 D_80097420;

void func_800F0188(struct X4_MainObj* arg0) {
    func_80017A04();
    ((void (*)(void*))func_8002D230)(arg0);
    if (--M2C_FIELD(arg0, s16*, 0x80) == -1) {
        arg0->x_speed = 0;
        arg0->y_speed = 0;
        arg0->x_accel = 0;
        arg0->gravity = 0;
        M2C_FIELD(arg0, s16*, 0x80) = 0x28;
        arg0->unk7++;
    }
    if (arg0->on_screen != 0 && !(D_80097420 & 0x1F)) {
        func_80016C48(2, 0xD, arg0);
    }
}
