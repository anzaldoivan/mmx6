#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800F4B3C(void* arg0) {
    if (M2C_FIELD(arg0, s32*, 0x24) < -0x40000) {
        M2C_FIELD(arg0, s32*, 0x24) = -0x40000;
    }
    if (M2C_FIELD(arg0, s32*, 0x24) > 0x40000) {
        M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
    }
    func_8002D230(arg0);
    {
        // !FAKE: velocity read lands in the first return register as in retail
        register s32 vx asm("$2") = M2C_FIELD(arg0, s32*, 0x24);
        if (vx > 0) {
            if (M2C_FIELD(arg0, u8*, 0x70) & 4) {
                func_80016C48(2, 0x7A, arg0);
                func_80029478(0x1E, 2, 2);
                M2C_FIELD(arg0, u8*, 0x93) = 0;
                M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
                M2C_FIELD(arg0, s32*, 0x2C) = 0;
                M2C_FIELD(arg0, u8*, 0x6)++;
            }
        } else if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            func_80016C48(2, 0x7A, arg0);
            func_80029478(0x1E, 2, 2);
            M2C_FIELD(arg0, u8*, 0x93) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0x20000;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, u8*, 0x6)++;
        }
    }
}
