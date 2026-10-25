#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CDBC();

void player_enter_ladder_step_off_bottom(void* arg0) {
    func_8003BA04(arg0, 0x1E);
    ((void (*)())func_8003CDBC)(arg0);
    ((u8*)arg0)[5] = 0xE;
    ((u8*)arg0)[6] = 3;
}
