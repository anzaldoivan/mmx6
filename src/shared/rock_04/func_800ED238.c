#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);    /* extern */
M2C_UNK set_animation(void*, M2C_UNK);          /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800ED238(void* arg0) {
    void* temp_a2;

    temp_a2 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 0x16) = 0;
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(temp_a2, u16*, 0x40);
    M2C_FIELD(arg0, s16*, 0x42) = M2C_FIELD(temp_a2, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(temp_a2, s32*, 0x30);
    M2C_FIELD(arg0, s32*, 0x3C) = M2C_FIELD(temp_a2, s32*, 0x3C);
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(temp_a2, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x14) = M2C_FIELD(temp_a2, u8*, 0x14);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x10);
    if (M2C_FIELD(arg0, s8*, 3) != 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x15, arg0);
    }
    ((void (*)(void*, s32))set_animation)(arg0, 4);
    M2C_FIELD(arg0, u8*, 6) = 0x3C;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}
