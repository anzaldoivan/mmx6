#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();
extern u8 D_800F7528[];

void func_800F4F44(void* arg0) {
    void* child;
    s16 n;

    n = ++M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0x17) {
        child = func_8002C458();
        if (child != 0) {
            u8 k = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(child, u8*, 1) = 0x1A;
            M2C_FIELD(child, u8*, 2) = 0xE;
            M2C_FIELD(child, void**, 0x7C) = arg0;
            M2C_FIELD(child, u8*, 0) = k;
        }
    } else if (n == 0x5A) {
        M2C_FIELD(arg0, u8*, 5) = D_800F7528[M2C_FIELD(arg0, u8*, 0x87)++ +
                                             M2C_FIELD(arg0, u8*, 0x86) * 6];
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
