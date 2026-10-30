#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void func_8003D18C(void* arg0);

s32 func_801EC298(void* arg0) {
    if (!(M2C_FIELD(arg0, u16*, 0x80) & 0x80)) {
        return 0;
    }
    func_8003BA04(arg0, 0x5F);
    play_sound(1, 1, arg0);
    func_8003CFE0(arg0, 7);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, u8*, 0x84) = 0;
    M2C_FIELD(arg0, u8*, 0x86) = 6;
    M2C_FIELD(arg0, u8*, 0x8C) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0xF8);
    M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x134);
    func_8003D18C(arg0);
    M2C_FIELD(arg0, u8*, 0x5) = 6;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    return 1;
}
