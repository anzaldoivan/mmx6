#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
s32 random_byte();                   /* extern */

void func_800F3988(void* arg0) {
    s32 a;
    s32 b;
    s32 c;

    if (M2C_FIELD(arg0, s8*, 2) >= 0x13) {
        set_animation(arg0, (random_byte() & 1) + 0x1D);
    } else {
        set_animation(arg0, (u8)((u32)random_byte() % 3) + 0x1D);
    }
    if (random_byte() & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    a = (u8)((u32)random_byte() % 40) + 20;
    b = (u8)((u32)random_byte() % 60) + 50;
    c = (u8)((u32)random_byte() % 10) + 15;
    b = (b << 16) / ((c * c) >> 1);
    M2C_FIELD(arg0, s32*, 0x2C) = b;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = b * c;
    switch (M2C_FIELD(arg0, s8*, 2)) {
    case 16:
    case 19:
        if (random_byte() & 1) {
            M2C_FIELD(arg0, s32*, 0x20) = (-a << 16) / c;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = (a << 16) / c;
        }
        break;
    case 17:
    case 20:
        M2C_FIELD(arg0, s32*, 0x20) = (-a << 16) / c;
        break;
    case 18:
    case 21:
        M2C_FIELD(arg0, s32*, 0x20) = (a << 16) / c;
        break;
    }
    M2C_FIELD(arg0, u8*, 6)++;
}
