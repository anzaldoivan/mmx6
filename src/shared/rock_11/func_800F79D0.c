#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800F79D0(void* arg0) {
    s32 v;
    s32 t;

    set_animation(arg0, (((u32)random_byte() % 3) & 0xFF) + 0x18);
    if (random_byte() & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if (random_byte() & 1) {
        M2C_FIELD(arg0, u16*, 0x5A) =
            M2C_FIELD(arg0, u16*, 0x5A) + (random_byte() & 0x3F);
    } else {
        M2C_FIELD(arg0, u16*, 0x5A) =
            M2C_FIELD(arg0, u16*, 0x5A) - (random_byte() & 0x3F);
    }
    switch (random_byte() & 3) {
    case 0:
        v = rcos(M2C_FIELD(arg0, s16*, 0x5A));
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x20) = v * 128 + t;
        v = -rsin(M2C_FIELD(arg0, s16*, 0x5A));
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x24) = v * 128 + t;
        break;
    case 1:
        v = rcos(M2C_FIELD(arg0, s16*, 0x5A));
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x20) = (v * 64 + t) * 2;
        v = -rsin(M2C_FIELD(arg0, s16*, 0x5A));
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x24) = (v * 64 + t) * 2;
        break;
    case 2:
        v = rcos(M2C_FIELD(arg0, s16*, 0x5A));
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x20) = (v * 32 + t) * 4 - t;
        v = -rsin(M2C_FIELD(arg0, s16*, 0x5A));
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x24) = (v * 32 + t) * 4 - t;
        break;
    case 3:
        v = rcos(M2C_FIELD(arg0, s16*, 0x5A));
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x20) = (v * 32 + t) * 4;
        v = -rsin(M2C_FIELD(arg0, s16*, 0x5A));
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x24) = (v * 32 + t) * 4;
        break;
    }
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}
