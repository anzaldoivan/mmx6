#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s32 D_8009718C;
extern s32 D_801F3794;
extern s32 D_801F37B4;

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801ECF64(u8* arg0) {
    s32 t;

    B(arg0, 3) = 1;
    if (SB(arg0, 1) == 9) {
        SB(arg0, 2) = 0;
        if (D_8009718C & 0x100) {
            W(arg0, 0x20) = 0xA0000;
        } else {
            W(arg0, 0x20) = 0x80000;
        }
    } else {
        SB(arg0, 2) = 1;
        if (D_8009718C & 0x100) {
            W(arg0, 0x20) = 0xC0000;
        } else {
            W(arg0, 0x20) = 0xA0000;
        }
    }
    t = SB(arg0, 2) * 4;
    W(arg0, 0x68) = t + (s32)&D_801F37B4;
    W(arg0, 0x50) = t + (s32)&D_801F3794;
    if (B(arg0, 0x15) == 0) {
        W(arg0, 0x20) = -W(arg0, 0x20);
    }
    W(arg0, 0x28) = 0;
    W(arg0, 0x24) = 0;
    W(arg0, 0x2C) = 0;
    func_800179A4(arg0, SB(arg0, 2) + 0x1A);
    B(arg0, 4)++;
    func_8002CCB0(arg0, 0x20, 0x14);
}
