#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ABS(x) ((x) < 0 ? -(x) : (x))

#define M2C_UNK s32
void func_800179A4(void*, M2C_UNK);

void func_800FC87C(void* arg0) {
    s8 t;

    func_800179A4(arg0, 4);
    t = M2C_FIELD(arg0, s8*, 0x88);
    if (t == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x200000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) + 6;
    } else if (t == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x400000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) + 6;
    } else if (t == 3) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            0x600000 / ABS(M2C_FIELD(arg0, s32*, 0x20));
    } else {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x800000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) - 6;
    }
    if (M2C_FIELD(arg0, s8*, 0x8B) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x200000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) + 8;
    }
    M2C_FIELD(arg0, u8*, 0x6)++;
}
