#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
extern s32 D_800F6F84;

void func_800F509C(u8* arg0) {
    u8* temp_s1;
    u16 temp_v0;

    temp_s1 = *(u8**)(arg0 + 0x7C);
    func_80017A04();
    if (*(s16*)(arg0 + 0x8C) == 0x18) {
        set_animation(arg0, 0xA);
    }
    temp_v0 = *(u16*)(arg0 + 0x8C);
    *(s16*)(arg0 + 0x8C) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0x1F) {
        temp_s1[0x8B] = 1;
        *(s32**)(arg0 + 0x50) = &D_800F6F84;
        *(s32*)(arg0 + 0x24) = 0;
        if (*(s8*)(arg0 + 2) == 0xB) {
            *(s32*)(arg0 + 0x20) = 0x100000;
        } else {
            *(s32*)(arg0 + 0x20) = 0xFFF00000;
        }
        play_sound(2, 0x72, arg0);
        ((void (*)(s32))func_80012D9C)(6);
        arg0[6]++;
    }
}
