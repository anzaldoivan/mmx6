#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
s32 random_byte();                   /* extern */
extern u8 D_800CCF5F;
extern s16 D_800F4480;

/* one arm per coin flip; the result-ignoring calls go through a void fn-ptr cast (C0103) */
#define ARM(off)                                                               \
    {                                                                          \
        s32 temp_v1 = M2C_FIELD(arg0, s16*, 0xE) - (off);                      \
        s32 temp_v0 = temp_v1 - D_800F4480;                                    \
        if (temp_v0 >= 0 ? temp_v0 < 0x10 : (D_800F4480 - temp_v1) < 0x10) {   \
            ((void (*)(void*, s32))set_animation)(arg0, 0);                    \
            M2C_FIELD(arg0, s16*, 0x7C) = 0x32;                                \
            if (D_800CCF5F < 2) {                                              \
                M2C_FIELD(arg0, s16*, 0x7E) = 3;                               \
            } else if (D_800CCF5F == 3) {                                      \
                M2C_FIELD(arg0, s16*, 0x7E) = 4;                               \
            } else {                                                           \
                M2C_FIELD(arg0, s16*, 0x7E) = 5;                               \
            }                                                                  \
            M2C_FIELD(arg0, u8*, 6) = 2;                                       \
        } else {                                                               \
            if (M2C_FIELD(arg0, s16*, 0xE) > D_800F4480 + (off)) {             \
                ((void (*)(void*, s32))set_animation)(arg0, 3);                \
                M2C_FIELD(arg0, s32*, 0x24) = 0x50000;                         \
            } else {                                                           \
                ((void (*)(void*, s32))set_animation)(arg0, 4);                \
                M2C_FIELD(arg0, s32*, 0x24) = 0xFFFB0000;                      \
            }                                                                  \
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;             \
        }                                                                      \
    }

void func_800EFAD4(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    if ((M2C_FIELD(arg0, s16*, 0x7C) = random_byte() & 1) == 0) {
        ARM(0x438)
    } else {
        ARM(0x468)
    }
}

#undef ARM
