#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();

void func_800F04C8(void* arg0, u8 arg1, s8 arg2, s32 arg3, s32 arg4) {
    s16 y = arg3;
    s16 z = arg4;
    void* obj;

    obj = alloc_sprite_slot();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 1;
        M2C_FIELD(obj, u8*, 1) = 0x2D;
        M2C_FIELD(obj, s8*, 2) = -0xB;
        M2C_FIELD(obj, s8*, 0x54) = arg2;
        M2C_FIELD(obj, u8*, 0x55) = arg1;
        M2C_FIELD(obj, u8*, 0x58) = 0;
        M2C_FIELD(obj, s16*, 0xA) = y;
        M2C_FIELD(obj, s16*, 0xE) = z;
    }
}
