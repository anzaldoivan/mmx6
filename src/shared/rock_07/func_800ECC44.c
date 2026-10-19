#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002BCCC(void*, s32);

void func_800ECC44(void* arg0, s32 arg1) {
    void* p;
    u8 b = arg1;

    p = func_8002BCCC(arg0, 0);
    if (p != 0) {
        M2C_FIELD(p, u8*, 0) = 0x41;
        M2C_FIELD(p, u8*, 1) = 0x10;
        M2C_FIELD(p, u8*, 0x15) = 0;
        M2C_FIELD(p, u8*, 2) = b;
        M2C_FIELD(p, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(p, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(p, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        {
            s32 t = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(p, void**, 0x80) = arg0;
            M2C_FIELD(p, u8*, 0x14) = t;
        }
    }
}
