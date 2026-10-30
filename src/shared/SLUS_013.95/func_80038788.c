#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void silence_sound(u8, u8);   /* extern */
M2C_UNK func_8002D5D0(void*); /* extern */
s32 func_8002FE30(void*);     /* extern */
M2C_UNK func_8003CD9C();      /* extern */

static inline s32 func_80038788_turn(void* arg0) {
    s32 res;
    s32 bad;
    u16 flags;

    silence_sound(1, 5);
    func_8003CD9C(arg0);
    flags = M2C_FIELD(arg0, u16*, 0x7C);
    res = 0;
    if (flags & 0xC) {
        res = 1;
        if (flags & 4) {
            M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x128);
        } else {
            res = 2;
            M2C_FIELD(arg0, s32*, 0x24) = -M2C_FIELD(arg0, s32*, 0x128);
        }
        func_8002D5D0(arg0);
        bad = func_8002FE30(arg0) != 0x2E;
        if (M2C_FIELD(arg0, s32*, 0x24) < 0 &&
            (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
            bad = 1;
        }
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
        if (bad) {
            res = 0;
        } else {
            func_8002D5D0(arg0);
        }
    }
    return res;
}

s32 func_80038788(void* arg0) {
    s32 res;
    s32 go;
    s32 mask;
    s32 bad;

    if (--M2C_FIELD(arg0, s8*, 0x85) != 0) {
        mask = 4;
        if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
            mask = 8;
        }
        go = (M2C_FIELD(arg0, u16*, 0x7C) & mask) == 0;
    } else {
        go = 1;
    }
    if (go) {
        return func_80038788_turn(arg0);
    }
    res = 2;
    if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
        res = 1;
    }
    func_8002D5D0(arg0);
    bad = func_8002FE30(arg0) != 0x2E;
    if (M2C_FIELD(arg0, s32*, 0x24) < 0 && (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
        bad = 1;
    }
    M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    if (bad) {
        res = 0;
    } else {
        func_8002D5D0(arg0);
    }
    if (res == 0) {
        res = func_80038788_turn(arg0);
        return res;
    }
    return res;
}
