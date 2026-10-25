#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);

void func_8003FF1C(void* arg0, s32 arg1) {
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0x26;
    if (arg1 == 0) {
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        func_8003BA04(arg0, 0xB9);
    } else {
        M2C_FIELD(arg0, u8*, 0x7) = 1;
        func_8003BA04(arg0, 0xBA);
    }
    M2C_FIELD(arg0, u8*, 0x86) = 0xA;
    player_spawn_visual(1, 0x1B, 6, 0);
}
