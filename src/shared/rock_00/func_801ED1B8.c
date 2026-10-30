#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern u32* D_8007789C[];
extern s32 D_80077AC8;
extern s32 D_8009718C;
extern s32 D_801F37A4;
extern s32 D_801F37A8;
extern s32 D_801F37BC;

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801ED1B8(u8* arg0) {
    u8* sc;
    u8* sc2;
    u8* sub;
    u8* src;
    s32 v;

    B(arg0, 3) = 1;
    sc = SCRATCH_1C;
    W(arg0, 0x3C) = (s32)(sc + W(sc, 0x30));
    sub = arg0 + 0x8C;
    W(arg0, 0x30) = (s32)D_8007789C;
    H(arg0, 0x40) = 0;
    H(arg0, 0x42) = 0x7802;
    if (SB(arg0, 1) == 0x14) {
        W(arg0, 0x50) = (s32)&D_801F37A4;
        B(arg0, 0x16) = 0;
        B(arg0, 0x64) = 1;
        W(arg0, 0x68) = (s32)&D_801F37BC;
        if (D_8009718C & 0x100) {
            W(arg0, 0x20) = 0xD0000;
        } else {
            W(arg0, 0x20) = 0xB0000;
        }
        if (B(arg0, 0x15) == 0) {
            W(arg0, 0x20) = -W(arg0, 0x20);
        }
        set_animation(arg0, 0x1D);
        B(sub, 2) = 0;
    } else {
        if (SB(arg0, 2) != 0) {
            src = *(u8**)(arg0 + 0x7C);
            H(arg0, 0xA) = H(src, 0xA);
            H(arg0, 0xE) = H(src, 0xE);
            B(arg0, 0x15) = B(src, 0x15);
            sc2 = SCRATCH_1C;
            v = W(sc2, 0x20);
            W(arg0, 0x30) = (s32)&D_80077AC8;
            H(arg0, 0x40) = 0;
            H(arg0, 0x42) = 0x784A;
            W(arg0, 0x3C) = (s32)(sc2 + v);
            set_animation(arg0, 2);
        } else {
            set_animation(arg0, 0x1E);
        }
        B(arg0, 0x16) = 1;
        W(arg0, 0x50) = (s32)&D_801F37A8;
        B(arg0, 0x64) = 2;
        W(arg0, 0x20) = 0;
        B(sub, 0) = 0x5A;
        B(sub, 1) = 8;
    }
    W(arg0, 0x28) = 0;
    W(arg0, 0x24) = 0;
    W(arg0, 0x2C) = 0;
    B(arg0, 5) = 0;
    B(arg0, 4)++;
    func_8002CCB0(arg0, 0x2A, 0x22);
}
