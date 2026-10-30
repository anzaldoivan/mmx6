#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_8009721E;

void func_800F59AC(void* arg0) {
    ((void (*)(M2C_UNK, M2C_UNK, void*))play_sound)(2, 0x5B, arg0);
    ((void (*)(void*, M2C_UNK))set_animation)(arg0, 3);
    if (H(arg0, 0xA) >= D_8009721E + 0xB0) {
        B(arg0, 0x15) = 0;
    } else {
        B(arg0, 0x15) = 0x40;
    }
    B(arg0, 0x6)++;
}
