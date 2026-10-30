#include "common.h"
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();

void func_800ED478(u8 arg0, s8 arg1, s16 arg2, s16 arg3, u8 arg4) {
    void* obj;

    obj = alloc_sprite_slot();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 1;
        M2C_FIELD(obj, u8*, 1) = 0x2D;
        M2C_FIELD(obj, u8*, 2) = arg0;
        M2C_FIELD(obj, s8*, 0x54) = arg1;
        M2C_FIELD(obj, u8*, 0x57) = arg4 + 1;
        M2C_FIELD(obj, u8*, 0x58) = 0;
        M2C_FIELD(obj, s16*, 0xA) = arg2;
        M2C_FIELD(obj, s16*, 0xE) = arg3;
    }
}
