#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);

void func_800F3E78(void* arg0) {
    ((void (*)())func_80017A04)();
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        play_sound(2, 0x74, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 4);
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 6) += 1;
    } else {
        func_8002D230(arg0);
    }
}
