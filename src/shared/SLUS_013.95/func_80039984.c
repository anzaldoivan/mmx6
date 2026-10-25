#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32 a0, s32 a1, void* arg2); /* extern */
s32 func_8003040C(void*);                      /* extern */
s32 func_800397F8(void*, s32);                 /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);         /* extern */
M2C_UNK func_8003CD9C();                       /* extern */

#define PICK(a, v)                                                             \
    switch (v) {                                                               \
    case 0x2D:                                                                 \
        a = 0;                                                                 \
        break;                                                                 \
    case 0x25:                                                                 \
    case 0x26:                                                                 \
    case 0x27:                                                                 \
    case 0x28:                                                                 \
        a = 1;                                                                 \
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {                                 \
            a = 2;                                                             \
        }                                                                      \
        break;                                                                 \
    default:                                                                   \
        a = 2;                                                                 \
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {                                 \
            a = 1;                                                             \
        }                                                                      \
        break;                                                                 \
    }

s32 func_80039984(void* arg0) {
    s32 v;
    s32 a;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, u8*, 0xE3) != 0) {
        if (--M2C_FIELD(arg0, u8*, 0xE3) != 0) {
            return 0;
        }
    }
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 4)) {
        return 0;
    }
    v = func_8003040C(arg0);
    if (v == 0x2E) {
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0 && M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003BA04(arg0, 0x90);
        } else {
            func_80016C48(0, 0x26, arg0);
            M2C_FIELD(arg0, s8*, 0x8E) = 0;
            func_8003BA04(arg0, 0xA0);
        }
        M2C_FIELD(arg0, s16*, 8) = 0;
        M2C_FIELD(arg0, s16*, 0xC) = 0;
        M2C_FIELD(arg0, s8*, 5) = 0x1B;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, u16*, 0xA) = (M2C_FIELD(arg0, u16*, 0xA) & 0xFFF0) + 8;
        func_8003CD9C(arg0);
        return 1;
    } else {
        if ((u8)(v - 0x25) >= 9) {
            return 0;
        }
        if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
            return 0;
        }
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0 && M2C_FIELD(arg0, s8*, 2) == 0) {
            PICK(a, v);
            func_8003BA04(arg0, a | 0x94);
        } else {
            func_80016C48(0, 0x26, arg0);
            PICK(a, v);
            func_8003BA04(arg0, a + 0xA3);
            M2C_FIELD(arg0, s8*, 0x8E) = 0;
        }
        M2C_FIELD(arg0, s8*, 5) = 0x1C;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        func_800397F8(arg0, v);
    }
    func_8003CD9C(arg0);
    return 1;
}

#undef PICK
