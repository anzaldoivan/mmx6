#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();

void func_800EF0B0(void* arg0, s32 arg1) {
    u8 b;
    s8* o;

    b = arg1;
    o = func_8002C458();
    if (o != 0) {
        M2C_FIELD(o, s8*, 0x0) = 0x41;
        M2C_FIELD(o, s8*, 0x1) = 0x1F;
        M2C_FIELD(o, u8*, 0x2) = b;
        M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(o, u16*, 0x8) = 0;
        M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(o, u16*, 0xC) = 0;
        M2C_FIELD(o, void**, 0x7C) = arg0;
    }
}
