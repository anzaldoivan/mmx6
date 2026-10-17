#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define HU(p, o) M2C_FIELD(p, u16*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

M2C_UNK func_80017A04();

void func_800F668C(void* arg0) {
    if (HU(arg0, 0x7C) & 1) {
        B(arg0, 0x3) = 1;
        func_80017A04();
    } else {
        B(arg0, 0x3) = 0;
    }
    if (--H(arg0, 0x7C) == 0) {
        B(arg0, 0x7) = 0;
        B(arg0, 0x3) = 0;
        B(arg0, 0x4) = 4;
    }
}
