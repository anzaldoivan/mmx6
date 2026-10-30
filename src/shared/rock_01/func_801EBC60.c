#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
s32 func_80039C40(void*);
s32 func_80039C9C(void*);
s32 func_80039CFC(void*);
s32 func_8003A3DC(void*);
void func_8003AAD0();
void func_8003AD18(void* arg0);
M2C_UNK func_8003AE8C(void*);
void func_8003B870(struct X4_PlayerObj* self);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CFE0(void*, M2C_UNK);
s32 start_rekkoha(u8* arg0);
void func_801EAE7C(void* arg0);
s32 func_801ECCD4(void*);
extern s8 D_800CCEDF;

static inline s32 func_801EBC60_h1(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        M2C_FIELD(arg0, u8*, 0xDD) = 1;
        if (start_rekkoha(arg0) != 0) {
            return 1;
        }
        M2C_FIELD(arg0, u8*, 0xDD) = 0;
    }
    return 0;
}

static inline s32 func_801EBC60_h2(void* arg0) {
    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    func_8003BA04(arg0, 0x58);
    play_sound(1, 7, arg0);
    if (random_byte() & 4) {
        func_8003CFE0(arg0, 3);
    }
    M2C_FIELD(arg0, u8*, 0x84) = 0;
    M2C_FIELD(arg0, u8*, 0x86) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0x30;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    func_801EAE7C(arg0);
    return 1;
}

static inline s32 func_801EBC60_h3(void* arg0) {
    if (func_8003A3DC(arg0) != 0) {
        return 1;
    }
    if (func_80039C9C(arg0) != 0) {
        return 1;
    }
    if (func_80039CFC(arg0) != 0) {
        func_8003AE8C(arg0);
        return 1;
    }
    return 0;
}

void func_801EBC60(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        if (func_80039C40(arg0) != 0) {
            return;
        }
        if (M2C_FIELD(arg0, u8*, 0x45) & 0x40) {
            if (func_801EBC60_h1(arg0) != 0) {
                return;
            }
            if (func_801EBC60_h2(arg0) != 0) {
                return;
            }
            if (func_801EBC60_h3(arg0) != 0) {
                return;
            }
        }
        M2C_FIELD(arg0, u8*, 0x8E) = 1;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        if (D_800CCEDF != 0) {
            func_8003B870(arg0);
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0xD0) != 0) {
            func_8003AAD0(arg0);
            return;
        }
        func_8003AD18(arg0);
    }
}
