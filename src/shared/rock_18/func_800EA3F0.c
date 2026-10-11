#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C530();

void func_800EA3F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void* obj;
    u8 a = arg0;
    s8 b = arg1;
    s16 c = arg2;
    s16 d = arg3;

    obj = func_8002C530();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 1;
        M2C_FIELD(obj, u8*, 1) = 0x2F;
        M2C_FIELD(obj, u8*, 2) = a;
        M2C_FIELD(obj, s8*, 0x54) = b;
        M2C_FIELD(obj, u8*, 0x57) = 0;
        M2C_FIELD(obj, s16*, 0xA) = c;
        M2C_FIELD(obj, s16*, 0xE) = d;
    }
}
