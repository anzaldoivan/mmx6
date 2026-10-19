#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

void func_800F2AF0(void* arg0) {
    u8* p;
    s32 t;

    M2C_FIELD(arg0, u8*, 3) = 0;
    p = SPAD;
    if (p[0x94] != 0) {
        p[0x94] = 0;
        SPAD[0x86] = 0x3C;
        t = SPAD[0x88];
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, u8*, 5) = t;
    }
}
