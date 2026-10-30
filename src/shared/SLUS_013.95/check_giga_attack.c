#include "common.h"
#define M2C_UNK s32
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CDF0();
#define func_8003CDF0 ((void (*)(void*))func_8003CDF0)
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
M2C_UNK func_8003DF58(void*);
M2C_UNK func_8003F0BC(void*);
M2C_UNK func_8003F480();
extern s8 D_800CCEEC;

#define B(o) (*(s8*)((u8*)self + (o)))
#define UB(o) (*(u8*)((u8*)self + (o)))
#define H(o) (*(s16*)((u8*)self + (o)))
#define UH(o) (*(u16*)((u8*)self + (o)))
#define W(o) (*(s32*)((u8*)self + (o)))

// 0x8003E344 check_giga_attack: giga attack input, armor checks, execution.
// basis: community tweaks-index.tsv:202
// callers: func_8003E06C, func_8003E174, func_8003E260, func_8003F13C and others
s32 check_giga_attack(void* self) {
    s32 ret;
    s32 m;
    s32 v;
    u8 k;

    ret = 0;
    if (B(0x2) != 0) {
        return ret;
    }
    if (UB(0x92) != 0) {
        return ret;
    }
    if (H(0xA8) != H(0x14A)) {
        return ret;
    }
    if (!(UH(0x80) & 0x40)) {
        return ret;
    }
    k = UB(0xE7);
    if ((u32)(k - 1) >= 4) {
        return 0;
    }
    if (k == 4) {
        if (B(0x86) != 0) {
            return 0;
        }
        m = 2;
        if (UB(0x15) != 0) {
            m = 1;
        }
        if (UB(0x89) & m) {
            return 0;
        }
    }
    func_8003CDF0(self);
    if (B(0x2) == 0) {
        UB(0x93) = 0;
        func_8003F480(self);
        func_8003DF58(self);
        func_8003F0BC(self);
    }
    UB(0x67) = 1;
    UB(0x61) = 0;
    UB(0xA4) = 0;
    if (UB(0xE7) != 4) {
        H(0xA8) = 0;
    }
    k = UB(0xE7);
    if (k == 1) {
        if (UB(0x89) & 8) {
            func_8003BA04(self, 0xAE);
        } else {
            func_8003BA04(self, 0xB1);
        }
        UB(0x5) = 0x24;
        player_spawn_visual(1, 0x1B, 8, 0);
        UB(0x86) = 5;
        UB(0xE1) = 0;
        W(0x68) = 0;
        UB(0xE0) = 2;
        ret = 1;
    } else if (k == 2) {
        if (UB(0x89) & 8) {
            func_8003BA04(self, 0xB9);
            UB(0x7) = 0;
        } else {
            func_8003BA04(self, 0xBA);
            UB(0x7) = 1;
        }
        UB(0x5) = 0x25;
        UB(0x86) = 5;
        UB(0xE1) = 0;
        W(0x68) = 0;
        UB(0xE0) = 2;
        player_spawn_visual(1, 0x1B, 7, 0);
        ret = 1;
    } else if (k == 3) {
        if (UB(0x89) & 8) {
            func_8003BA04(self, 0xB9);
            UB(0x7) = 0;
        } else {
            func_8003BA04(self, 0xBA);
            UB(0x7) = 1;
        }
        UB(0x5) = 0x4D;
        UB(0x86) = 5;
        UB(0xE1) = 0;
        W(0x68) = 0;
        UB(0xE0) = 2;
        ret = 1;
    } else {
        func_8003BA04(self, 0x6A);
        {
            // !FAKE: depin: dropping it breaks the match (143/180)
            register s32 c asm("$2");
            c = 0x22;
            UB(0x5) = c;
            c = 5;
            UB(0x86) = c;
            c = 0x18;
            UB(0x84) = 0;
            UB(0x8C) = 0;
            UB(0xE1) = c;
        }
        if (UB(0x15) != 0) {
            W(0x20) = 0x28000;
        } else {
            W(0x20) = -0x28000;
        }
        W(0x24) = 0x38000;
        W(0x28) = 0;
        ret = 1;
        UB(0xE0) = ret;
        UB(0x7) = 0;
        W(0x2C) = W(0x100);
    }
    UB(0x7A) = 1;
    D_800CCEEC = 1;
    UB(0x6) = 0;
    return ret;
}
