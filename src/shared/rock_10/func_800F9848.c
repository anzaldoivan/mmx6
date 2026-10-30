#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;
extern M2C_UNK D_800FC73C;

void func_800F9848(void* arg0) {
    s32 x;

    play_sound(2, 0x21, arg0);
    M2C_FIELD(arg0, u8*, 0x60) = 0xA;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
    set_animation(arg0, 0x12);
    x = M2C_FIELD(arg0, s16*, 0xA);
    if (D_800970AA >= x) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFF40000;
        M2C_FIELD(arg0, s32*, 0x28) = 0x4CCC;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0xC0000;
        M2C_FIELD(arg0, s32*, 0x28) = 0x4CCC;
    }
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800FC73C;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}
