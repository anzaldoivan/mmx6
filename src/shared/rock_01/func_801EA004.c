#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
s32 func_8002FE30(void*);
M2C_UNK func_8003AF1C(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CD9C();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
s32 func_801ECCD4();

s32 func_801EA004(void* arg0) {
    s32 var_v0;

    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    func_8003BA04(arg0, 0x6A);
    play_sound(1, 7, arg0);
    if (random_byte() & 4) {
        func_8003CFE0(arg0, 8);
    }
    ((void (*)(void*))func_8003CD9C)(arg0);
    M2C_FIELD(arg0, u8*, 0x5) = 0x3D;
    M2C_FIELD(arg0, u8*, 0x6) = 1;
    if (M2C_FIELD(arg0, u16*, 0x80) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x80) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        if (M2C_FIELD(arg0, u16*, 0x80) & 0x80) {
            func_8003AF1C(arg0);
            return 1;
        }
        {
            s32 one = 1;
            M2C_FIELD(arg0, u8*, 0x8E) = one;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        var_v0 = func_8002FE30(arg0);
        if (var_v0 == 0x2E) {
            var_v0 = 0x1B;
        } else {
            var_v0 = 0x1C;
        }
        M2C_FIELD(arg0, u8*, 0x5) = var_v0;
        M2C_FIELD(arg0, u8*, 0x6) = 1;
    }
    return 1;
}
