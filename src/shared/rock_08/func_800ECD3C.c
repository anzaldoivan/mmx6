#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;
#include "mmx6/state.h"

void func_800ECD3C(void* arg0) {
    s32 a;
    s32 b;

    a = M2C_FIELD(arg0, u16*, 0x82) - 1;
    b = M2C_FIELD(arg0, u16*, 0x84) + 1;
    M2C_FIELD(arg0, u16*, 0x82) = a;
    M2C_FIELD(arg0, u16*, 0x84) = b;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = a;
    } else {
        D_800970AA = b;
    }
    {
        if (D_80097420.transition.active == 0) {
            M2C_FIELD(arg0, s16*, 0x80) = 0;
            M2C_FIELD(arg0, u8*, 7) = M2C_FIELD(arg0, u8*, 7) + 1;
        }
    }
}
