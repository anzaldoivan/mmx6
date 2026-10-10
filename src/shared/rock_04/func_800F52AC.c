#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* func_8002C398(void);

void func_800F52AC(void* arg0, u8 arg1) {
    void* v;

    v = func_8002C398();
    if (v != 0) {
        M2C_FIELD(v, u8*, 0x0) = 0x41;
        M2C_FIELD(v, u8*, 0x1) = 8;
        M2C_FIELD(v, u8*, 0x2) = arg1;
        M2C_FIELD(v, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(v, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(v, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(v, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(v, u16*, 0x8) = 0;
        M2C_FIELD(v, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(v, u16*, 0xC) = 0;
        M2C_FIELD(v, void**, 0x50) = arg0;
        M2C_FIELD(v, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(v, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(v, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
    }
}
