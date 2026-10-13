#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(M2C_UNK);
M2C_UNK func_8002B838();
void func_800ED50C(s32, s32, s32, s32);
void func_800ED58C(u8, s8, s16, s16, u8);
void func_800ED61C(s32, s32, s32, s32);
extern s32 D_80070CC4[];
extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_80097427;

void func_800EA62C(u8* arg0) {
    ((void (*)())func_8002B838)();
    if (*(u8*)D_80070CC4 != 0xFF) {
        D_80097427 = 0;
        func_800ED58C(0x1F, 0, 0x108, 0x80, 0);
        arg0[1] += 1;
    } else {
        D_80097427 = 1;
        func_800ED58C(0x28, 0, 0x108, 0x80, 0);
        arg0[1] += 2;
    }
    func_800ED50C(0x1C, 0, 0x130, 0x30);
    func_800ED50C(0x1E, 0, 0x108, 0x54);
    func_800ED58C(0x20, 0, 0x108, 0xA8, 1);
    func_800ED50C(0x1B, 0, 0xE0, 0xD0);
    func_800ED50C(0x1D, 0, 0x180, 0xD0);
    func_800ED61C(0, 1, 0, 0);
    D_800971F8[0].unk3 = 1;
    D_800971F8[0].x_pos.i.hi = 0x200;
    D_800971F8[0].y_pos.i.hi = 0;
    D_800971F8[0].unk4C = 1;
    D_800971F8[1].unk3 = 0;
    D_800971F8[2].unk3 = 0;
    ((void (*)(s32))func_800139A0)(8);
}
