#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6E48(struct X4_MainObj*);

void func_800F4F58(struct X4_MainObj* arg0) {
    play_sound(2, 0x5B, arg0);
    set_animation(arg0, 3);
    func_800F6E48(arg0);
    *((u8*)arg0 + 6) = *((u8*)arg0 + 6) + 1;
}
