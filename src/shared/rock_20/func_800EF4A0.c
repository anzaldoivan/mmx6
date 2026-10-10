#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800C4570;
extern s8 D_800CCEF8;

void func_800EF4A0(void* arg0) {
    if (D_800C4570 & 0x8FF) {
        D_800CCEF8 = 0x6F;
        M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    }
}
