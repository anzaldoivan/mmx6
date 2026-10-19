#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA1A4(void* arg0) {
    s32 y;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    s32 e;

    M2C_FIELD(arg0, s32*, 0x44) += 0xFFFE7AE2;
    y = M2C_FIELD(arg0, s8*, 2) * 2 + 0xA4;
    if (y >= M2C_FIELD(arg0, s16*, 0x46)) {
        M2C_FIELD(arg0, s16*, 0x46) = y;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
    a = M2C_FIELD(arg0, u16*, 0x46);
    b = M2C_FIELD(arg0, u16*, 0x42);
    c = M2C_FIELD(arg0, u16*, 0x4A);
    d = M2C_FIELD(arg0, u16*, 0x3A);
    e = a + 2;
    M2C_FIELD(arg0, s16*, 0x3E) = e;
    M2C_FIELD(arg0, s16*, 0x16) = b - c;
    M2C_FIELD(arg0, s16*, 0x1A) = a;
    M2C_FIELD(arg0, s16*, 0x1E) = b + c;
    M2C_FIELD(arg0, s16*, 0x22) = a;
    M2C_FIELD(arg0, s16*, 0x26) = d + c;
    M2C_FIELD(arg0, s16*, 0x2A) = e;
    M2C_FIELD(arg0, s16*, 0x2E) = d - c;
    M2C_FIELD(arg0, s16*, 0x32) = e;
}
