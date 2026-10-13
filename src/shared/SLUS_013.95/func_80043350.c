#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();

void func_80043350(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x36) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
    M2C_FIELD(arg0, u8*, 0x2) = func_8002D2D4() & 1;
    M2C_FIELD(arg0, u8*, 0x0) = 3;
    M2C_FIELD(arg0, s16*, 0x34) = (func_8002D2D4() & 1) + 0x1A;
    M2C_FIELD(arg0, s8*, 0x37) = -1;
    M2C_FIELD(arg0, s16*, 0xA) = 0;
    M2C_FIELD(arg0, s16*, 0xE) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, s16*, 0x48) =
        M2C_FIELD(arg0, s16*, 0x46) - ((func_8002D2D4() % 60) + 0x78) * 0xB;
    M2C_FIELD(arg0, s16*, 0x4A) = ((func_8002D2D4() & 3) + 3) * 0xB;
    M2C_FIELD(arg0, s16*, 0x4E) = func_8002D2D4() % 3;
}
