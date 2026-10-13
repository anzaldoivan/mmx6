#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
extern M2C_UNK D_8007433C;
extern s32 D_80074B5C;
extern s8 D_8009711A;
extern s32 D_800FB1A4;
extern s32 D_800FBC70;

void func_800EDD60(void* arg0) {
    s32 r;
    u8 t;

    r = func_80031474(arg0);
    if (r < 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        D_800FBC70 = 1;
        D_8009711A = 1;
        func_8002CCB0(arg0, 0x64, 0x64);
        return;
    }
    M2C_FIELD(arg0, u8*, 0x88) |= func_80030ECC(arg0);
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, u8*, 0x84) = ((u32)(r - 0x19) < 2) ? 2 : 0x1E;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    }
    if (M2C_FIELD(arg0, s8*, 5) == 0x63) {
        M2C_FIELD(arg0, u8*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, s8*, 5) = 0xA;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
    t = M2C_FIELD(arg0, u8*, 0x84);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x84) = t + 0xFF;
        if (t & 8) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_80074B5C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    ((void (**)(void*)) & D_800FB1A4)[M2C_FIELD(arg0, s8*, 5)](arg0);
}
