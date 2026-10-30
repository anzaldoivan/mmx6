#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class4_slot();

void func_800ECCD8(void* arg0, s32 arg1) {
    void* e;
    u8 b = arg1;
    s32 y;

    e = alloc_class4_slot();
    if (e != 0) {
        M2C_FIELD(e, u8*, 0) = 0x41;
        M2C_FIELD(e, u8*, 1) = 0xA;
        M2C_FIELD(e, u8*, 2) = b;
        M2C_FIELD(e, s32*, 8) = M2C_FIELD(arg0, s16*, 0xA);
        y = M2C_FIELD(arg0, s16*, 0xE);
        M2C_FIELD(e, void**, 0x7C) = arg0;
        M2C_FIELD(e, s32*, 0xC) = y;
        M2C_FIELD(e, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(e, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(e, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(e, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(e, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
    }
}
