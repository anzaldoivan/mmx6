#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F6BF2;
extern s16 D_800F6BF4;

#define POS M2C_FIELD(arg0, s16*, 0xA)

#define STEP(D)                                                                \
    {                                                                          \
        p = POS;                                                               \
        lim = D;                                                               \
        q = POS;                                                               \
        raw = D;                                                               \
        if (p < lim) {                                                         \
            POS = q + 3;                                                       \
            if (POS < lim)                                                     \
                goto ok;                                                       \
        } else {                                                               \
            POS = q - 3;                                                       \
            if (lim < POS)                                                     \
                goto ok;                                                       \
        }                                                                      \
        POS = raw;                                                             \
        M2C_FIELD(arg0, s8*, 7) = 1;                                           \
    }

void func_800F0ED8(void* arg0) {
    s32 lim;
    u16 raw;
    s32 p;
    u16 q;

    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        STEP(D_800F6BF2)
    } else {
        STEP(D_800F6BF4)
    }
ok:
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
