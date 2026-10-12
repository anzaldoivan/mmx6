#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();

void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3) {
    void* obj;

    obj = func_8002C458();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0x0) = 0x41;
        M2C_FIELD(obj, u8*, 0x1) = 0x16;
        M2C_FIELD(obj, u8*, 0x2) = arg1;
        M2C_FIELD(obj, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(obj, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(obj, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(obj, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(obj, s16*, 0xA) = arg2;
        M2C_FIELD(obj, s16*, 0x8) = 0;
        M2C_FIELD(obj, s16*, 0xE) = arg3;
        M2C_FIELD(obj, s16*, 0xC) = 0;
        M2C_FIELD(obj, void**, 0x7C) = arg0;
    }
}
