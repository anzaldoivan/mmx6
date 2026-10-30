#include "common.h"
#define M2C_UNK s32

void func_80012D9C(s32);
s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_800CCEF6;

#define UNK20(p) (*(s32*)((u8*)(p) + 0x20))

void func_8004755C(Probe800473EC* arg0) {
    if (D_800CCEF6 != 0) {
        s32 q;
        s32 v;

        func_80029478(0x3C, 2, 2);
        v = arg0->unk18;
        q = 0x500000 / (v < 0 ? -v : v);
        arg0->unk14 = 0x32;
        q -= (u16)arg0->unk16;
        arg0->unk16 = q;
        UNK20(arg0) = arg0->unk1C;
        play_sound(2, 0x23, 0);
        func_80012D9C(5);
        {
            // !FAKE: depin: dropping it breaks the match (68/70)
            register s32 c asm("$2") = -0x10000;
            // !FAKE: depin: dropping it breaks the match (67/70)
            register s32 k asm("$3") = 5;

            arg0->unk18 = c;
            arg0->unk5 = k;
        }
        return;
    }
    arg0->unk1C += arg0->unk18;
    if (--arg0->unk16 == 0) {
        func_80029478(0x3C, 2, 2);
        arg0->unk5 = 4;
        play_sound(2, 0x23, 0);
        func_80012D9C(5);
        {
            s32 t = arg0->unk1C;
            // !FAKE: depin: dropping it breaks the match (64/70)
            register s32 c asm("$2");

            c = -0x10000;
            arg0->unk18 = c;
            c = 0x28;
            arg0->unk14 = c;
            UNK20(arg0) = t;
        }
    }
}
