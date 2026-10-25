#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D330();
extern struct X4_BackgroundObj background_objects[3];

void func_800EC4D4(void* arg0) {
    struct X4_BackgroundObj* bg = background_objects;

    if (M2C_FIELD(bg, s16*, 0x96) >= -0x4F) {
        M2C_FIELD(bg, s16*, 0x96) = M2C_FIELD(bg, s16*, 0x96) - 1;
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_8002943C(0xA, 2, 2);
            M2C_FIELD(arg0, s16*, 0x7C) = 0xA;
            return;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = M2C_FIELD(arg0, s16*, 0x7C) - 1;
        return;
    }
    func_8003D330();
    M2C_FIELD(bg, s16*, 0x24) = 0x1C00;
    M2C_FIELD(bg, u8*, 0x57) = 0;
    M2C_FIELD(arg0, u8*, 4) = 2;
}
