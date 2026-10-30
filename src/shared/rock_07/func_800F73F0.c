#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800F73F0(void* arg0) {
    s32 ang;

    set_animation(arg0, (((u32)random_byte() % 3) & 0xFF) + 0x1D);
    if (random_byte() & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    ang = (M2C_FIELD(arg0, s32*, 0x84) + 0x800) & 0xFFF;
    M2C_FIELD(arg0, u16*, 0x90) = M2C_FIELD(arg0, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0x92) = M2C_FIELD(arg0, u16*, 0xE);
    M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x90) + (rcos(ang) >> 3);
    M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x92) + (rsin(ang) >> 3);
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}
