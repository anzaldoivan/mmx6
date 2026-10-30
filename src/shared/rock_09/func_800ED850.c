#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
void func_800ED18C(s32 arg0, s32 arg1, u8* arg2);
extern s8 D_800CCEF6;
extern s32 D_800F6BA4;
extern s16 D_800F6BC4[16];

void func_800ED850(u8* arg0) {
    if (D_800CCEF6 != 0) {
        arg0[4] -= 2;
        return;
    }
    if (*(u16*)(arg0 + 0x1A) != 0) {
        (*(u16*)(arg0 + 0x1A))--;
    }
    func_8002B410((M2C_UNK*)D_800F6BC4, &D_800F6BA4, 0x10,
                  0x1E - *(u16*)(arg0 + 0x1A), 0x1E);
    load_palette(0x63, (M2C_UNK*)D_800F6BC4, 1);
    func_800ED18C(0x1E - *(u16*)(arg0 + 0x1A), 0x1E, arg0);
    if (*(u16*)(arg0 + 0x1A) == 0) {
        arg0[4] -= 3;
        play_sound(5, 3, 0);
    }
}
