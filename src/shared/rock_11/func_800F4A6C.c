#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F4A6C(void* arg0) {
    void* parent;
    s32 state;

    parent = M2C_FIELD(arg0, void**, 0x50);
    if (M2C_FIELD(parent, u8*, 0x7) & 4) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x4) += 1;
        return;
    }
    state = M2C_FIELD(arg0, u8*, 0x2) & 0xF;
    if (state == 1) {
        if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            M2C_FIELD(arg0, u8*, 0x4) += 1;
            return;
        }
    } else if (state == 2 && M2C_FIELD(arg0, s8*, 0x45) == 1) {
        set_animation(arg0, 0);
    }
    M2C_FIELD(arg0, s16*, 0xA) =
        M2C_FIELD(parent, s16*, 0xA) + M2C_FIELD(arg0, s16*, 0x8);
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(parent, s16*, 0xE) + M2C_FIELD(arg0, s16*, 0xC);
}
