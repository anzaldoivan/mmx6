#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80017A04();
M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_80051FE8(void* arg0, void* arg1);
extern s8 D_80097182;

void func_80051780(s8* arg0) {
    s32 temp_a1;

    temp_a1 = *(s32*)(arg0 + 0x50);
    if (arg0[4] == 0) {
        ((void (*)())func_80051FE8)(arg0, temp_a1);
        *(s16*)(arg0 + 0x54) = 0x78;
        play_sound(0, 0x24, 0);
    } else if (*(s16*)(arg0 + 0x54) == 0) {
        D_80097182 = 2;
        clear_object_slot(arg0, temp_a1);
        return;
    } else {
        ((void (*)())func_80017A04)(arg0, temp_a1);
        (*(s16*)(arg0 + 0x54))--;
    }
    func_8002CCB0((struct X4_BaseObj*)arg0, 0x88, 0x88);
}
