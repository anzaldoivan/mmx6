#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CD9C();
M2C_UNK func_8003CDBC();

void player_enter_ladder_climb_on_top(void* arg0) {
    ((void (*)(void*, s32))func_8003BA04)(arg0, 0x1D);
    M2C_FIELD(arg0, s16*, 8) = 0;
    M2C_FIELD(arg0, s16*, 0xC) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, u16*, 0xA) = (M2C_FIELD(arg0, u16*, 0xA) & 0xFFF0) + 8;
    ((void (*)())func_8003CD9C)(arg0);
    ((void (*)())func_8003CDBC)(arg0);
    M2C_FIELD(arg0, u8*, 5) = 0xE;
    M2C_FIELD(arg0, u8*, 6) = 2;
}
