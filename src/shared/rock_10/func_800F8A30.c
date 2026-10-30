#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F9E3C(void*, s32);
extern M2C_UNK D_80074E7C;
extern s32 D_800FD004;

void func_800F8A30(void* arg0) {
    s8 st = M2C_FIELD(arg0, s8*, 0x45);

    if (st == 1) {
        if (random_byte() & 1) {
            play_sound(2, 0x24, arg0);
        } else {
            play_sound(2, 0x25, arg0);
        }
        set_animation(arg0, 0xA);
        M2C_FIELD(arg0, void**, 0x58) = &D_80074E7C;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        D_800FD004 = 0;
        func_800F9E3C(arg0, 0x10);
        func_800F9E3C(arg0, 0x11);
        func_800F9E3C(arg0, 0x12);
        func_800F9E3C(arg0, 0x13);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x258;
        M2C_FIELD(arg0, u8*, 7) = 1;
        M2C_FIELD(arg0, u8*, 6)++;
    } else if (st == 2) {
        play_sound(2, 0x57, arg0);
    }
}
