#include "common.h"

void func_800ED50C(u8 arg0, s8 arg1, s16 arg2, s16 arg3);
void func_800ED58C(u8 arg0, s8 arg1, s16 arg2, s16 arg3, u8 arg4);
void func_800ED61C(s32, s32, s32, s32);
extern s32 D_80070CC4[];
extern u8 D_80097427;

void func_800ED22C(u8* arg0) {
    if (*(u8*)D_80070CC4 != 0xFF) {
        D_80097427 = 0;
        func_800ED58C(0x1F, 0, 0x108, 0x80, 0);
        arg0[1] = 1;
    } else {
        D_80097427 = 1;
        func_800ED58C(0x28, 0, 0x108, 0x80, 0);
        arg0[1] = 2;
    }
    func_800ED50C(0x1C, 0, 0x130, 0x30);
    func_800ED50C(0x1E, 0, 0x108, 0x54);
    func_800ED58C(0x20, 0, 0x108, 0xA8, 1);
    func_800ED50C(0x1B, 0, 0xE0, 0xD0);
    func_800ED50C(0x1D, 0, 0x180, 0xD0);
    func_800ED61C(0, 1, 0, 0);
}
