#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_8007429C;
extern M2C_UNK D_8007433C;

void func_800F70B8(void* arg0) {
    s32 kind;
    s8 one;
    s32 four;

    M2C_FIELD(arg0, u8*, 0x3) = 0;
    one = M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x4);
    if (one != 1) {
        M2C_FIELD(arg0, u8*, 0x4) = 2;
        return;
    }
    four = 4;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = one;
    M2C_FIELD(arg0, u8*, 0x16) = four;
    M2C_FIELD(arg0, u8*, 0x67) = one;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = one;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x7) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    kind = M2C_FIELD(arg0, s8*, 0x2) & 0xF0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (kind == 0) {
        func_80016C48(2, 0x45, arg0);
        ((void (*)(void*, s32))func_800179A4)(arg0, 9);
        M2C_FIELD(arg0, u8*, 0x60) = four;
        M2C_FIELD(arg0, u8*, 0x16) = four;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u16*, 0xA) -= 0x20;
        } else {
            M2C_FIELD(arg0, u16*, 0xA) += 0x20;
        }
        M2C_FIELD(arg0, s32*, 0x84) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        M2C_FIELD(arg0, u16*, 0xE) -= 8;
    } else if (kind == 0x10) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xD);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007429C;
        M2C_FIELD(arg0, u8*, 0x60) = 6;
        M2C_FIELD(arg0, u8*, 0x16) = four;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = one;
    } else if (kind == 0x20) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xE);
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(arg0, u8*, 0x16) = four;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
    } else if (kind == 0x30) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xD);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007429C;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u16*, 0xA) -= 0x1E;
        } else {
            M2C_FIELD(arg0, u16*, 0xA) += 0x1E;
        }
        M2C_FIELD(arg0, u8*, 0x60) = 6;
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        M2C_FIELD(arg0, u8*, 0x5) = 3;
        M2C_FIELD(arg0, u16*, 0xE) -= 8;
    }
}
