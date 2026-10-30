#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();

void func_800ED3F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 a = arg0;
    s8 b = arg1;
    s16 c = arg2;
    s16 d = arg3;
    void* obj = alloc_sprite_slot();

    if (obj != 0) {
        M2C_FIELD(obj, s8*, 0) = 1;
        M2C_FIELD(obj, s8*, 1) = 0x2D;
        M2C_FIELD(obj, s8*, 2) = a;
        M2C_FIELD(obj, s8*, 0x54) = b;
        M2C_FIELD(obj, s8*, 0x57) = 0;
        M2C_FIELD(obj, s8*, 0x58) = 0;
        M2C_FIELD(obj, s16*, 0xA) = c;
        M2C_FIELD(obj, s16*, 0xE) = d;
    }
}
