#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003B298(void*);
s32 start_hover(struct X4_PlayerObj* self);
s32 start_falcon_dash(void*);
s32 func_8003F32C(void*);
s32 func_801EC298(void*);

static inline s32 func_8003906C_inl(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x87) == 0 &&
        !(M2C_FIELD(arg0, u16*, 0x80) & 0x100)) {
        return 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if (M2C_FIELD(arg0, u8*, 0x89) & 1) {
            return 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x104);
    } else {
        if (M2C_FIELD(arg0, u8*, 0x89) & 2) {
            return 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x104);
    }
    return 1;
}

// 0x8003906C select_air_dash: air dash picked by armor.
// basis: community tweaks-index.tsv:216
// callers: func_800368FC, func_80036D4C, func_801EAA38, func_801EB324 and others
s32 select_air_dash(void* arg0) {
    u8 t;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x86) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        t = M2C_FIELD(arg0, u8*, 0xE7);
        if (t == 1) {
            return start_falcon_dash(arg0) != 0;
        }
        if (t == 3) {
            if (func_8003F32C(arg0) != 0) {
                return 1;
            }
        } else if (start_hover(arg0) != 0) {
            return 1;
        }
    } else if (func_801EC298(arg0) != 0) {
        return 1;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x92) != 0) {
            return 0;
        }
        if (M2C_FIELD(arg0, u8*, 0xE7) != 4) {
            return 0;
        }
    }
    if (func_8003906C_inl(arg0) != 0) {
        func_8003B298(arg0);
        return 1;
    }
    return 0;
}
