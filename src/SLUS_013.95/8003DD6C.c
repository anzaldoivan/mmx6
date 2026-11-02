#include "common.h"
#define M2C_UNK s32
s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_8003F480();
extern s8 D_800CCEEC;
extern s8 D_80073ED8[];
extern s8 D_80073EE4[];
extern s8 D_80073EF0[];

#define B(o) (*(s8*)((u8*)self + (o)))
#define UB(o) (*(u8*)((u8*)self + (o)))
#define UH(o) (*(u16*)((u8*)self + (o)))

void func_8003DD6C(void* self) {
    s32 a;
    s32 m;
    s8 i;
    s8 k;

    if (B(0xD3) != 0) {
        return;
    }
    if (B(0x99) != 0) {
        return;
    }
    if (B(0xD5) != 0) {
        return;
    }
    if (B(0xE0) != 0) {
        return;
    }
    if (D_800CCEEC != 0) {
        return;
    }
    k = B(0x5);
    if (k == 0x2D) {
        return;
    }
    if (k == 0x2E) {
        return;
    }
    if (k == 0x2F) {
        return;
    }
    if (k == 0x4C) {
        return;
    }
    a = UH(0x7C) & 0x600;
    m = UH(0x80) & 0x600;
    if (a == 0x600 || m == 0x600) {
        if (B(0x93) != 0) {
            UB(0x93) = 0;
            func_8003F480(self);
            play_sound(0, 0xC, 0);
        }
    } else if (m != 0) {
        i = D_80073EF0[B(0x93)];
        if (m & 0x200) {
            do {
                i++;
                if (i == 9) {
                    i = 0;
                    break;
                }
            } while (!(D_80073ED8[i] & UB(0xC9)));
        } else {
            do {
                i--;
                if (i < 0) {
                    i = 8;
                }
                if (i == 0) {
                    break;
                }
            } while (!(D_80073ED8[i] & UB(0xC9)));
        }
        i = D_80073EE4[i];
        if (B(0x93) != i) {
            B(0x93) = i;
            func_8003F480(self);
            play_sound(0, 0xC, 0);
        }
    }
}

#include "common.h"
#define M2C_UNK s32
void func_8003F7BC(void* arg0, M2C_UNK arg1, M2C_UNK arg2);

#define B(o) (*(s8*)((u8*)self + (o)))
#define UB(o) (*(u8*)((u8*)self + (o)))
#define W(o) (*(s32*)((u8*)self + (o)))

M2C_UNK func_8003DF58(void* self) {
    u8 t;
    // !FAKE: depin: dropping it breaks the match (62/69)
    register s32 k asm("$6");

    t = UB(0xE7);
    k = 2;
    if (t == k) {
        if (W(0x144) == 6 && B(0x5) != 0x1F) {
            func_8003F7BC(self, 1, k);
            return;
        }
        UB(0x94) = 0x32;
        UB(0x95) = 0x2D;
        if (B(0x9C) == 2 || (W(0xEC) & 0x80000)) {
            UB(0x95) = 0x2E;
        }
    } else {
        UB(0x94) = UB(0x93);
        if (B(0x94) != 0) {
            if (B(0x9B) == k) {
                UB(0x94) += 9;
            } else if ((W(0xEC) & 0x80000) && (t == 1 || t == 4 || t == 3)) {
                UB(0x94) += 9;
            }
        } else {
            UB(0x94) = 0x32;
        }
        UB(0x95) = 0;
        func_8003F7BC(self, 1, k);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 check_giga_attack(void* self);
void func_8003E614(void* arg0);
M2C_UNK start_player_attack(void*, M2C_UNK);
extern s8 D_80073E00[];

#define B(o) (*(s8*)((u8*)arg0 + (o)))

s32 func_8003E06C(void* arg0) {
    s8 k;

    if (B(0xD3) != 0) {
        return 0;
    }
    if (B(0x2) != 0) {
        return 0;
    }
    if (check_giga_attack(arg0) != 0) {
        return 1;
    }
    func_8003E614(arg0);
    if (B(0x8F) == 0) {
        return 0;
    }
    k = B(0x96);
    if (D_80073E00[k] == 0) {
        return 0;
    }
    B(0x84) = 0;
    B(0x86) = 0;
    B(0x8C) = 0;
    if (k == 5 || k == 14) {
        if (B(0x5) == 0x1B) {
            func_8003BA04(arg0, 0x91);
        } else {
            func_8003BA04(arg0, 0x97);
        }
    } else if (k == 50) {
        ((void (*)(void*))func_8003AFF4)(arg0);
    } else {
        // !FAKE: goto: default arm jumps to the shared tail label (C0115)
        goto def;
    }
    start_player_attack(arg0, 1);
    return 1;
def:
    ((void (*)(void*, s32))start_player_attack)(arg0, 0);
    return 1;
}
#undef B

#include "common.h"
#define M2C_UNK s32
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 check_giga_attack(void* self);
void func_8003E614(void* arg0);
M2C_UNK start_player_attack(void*, M2C_UNK);
extern s8 D_80073E00[];

#define B(o) (*(s8*)((u8*)self + (o)))

s32 func_8003E174(void* self) {
    s8 t;
    s8 u;

    if (B(0xD3) != 0) {
        return 0;
    }
    if (B(0x2) != 0) {
        return 0;
    }
    if (check_giga_attack(self) != 0) {
        return 1;
    }
    func_8003E614(self);
    if (B(0x8F) == 0) {
        return 0;
    }
    t = B(0x96);
    if (D_80073E00[t] == 0) {
        return 0;
    }
    if (t != 0x32) {
        B(0x84) = 0;
    }
    u = B(0x96);
    B(0x8C) = 0;
    if (u == 5 || u == 0xE) {
        if (B(0x5) == 0xB) {
            func_8003BA04(self, 0x7F);
        } else {
            func_8003BA04(self, 0x7A);
        }
    }
    start_player_attack(self, 1);
    return 1;
}

#undef B

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 check_giga_attack(void* self);
void func_8003E614(void* arg0);
M2C_UNK start_player_attack(void*, M2C_UNK);
void func_801EB6E8(void* arg0);
extern s8 D_80073E00[];

s32 func_8003E260(void* arg0) {
    s8* p = arg0;
    s8 idx;

    if (p[0xD3] != 0) {
        return 0;
    }
    if (p[2] != 0) {
        return 0;
    }
    if (check_giga_attack(arg0) != 0) {
        return 1;
    }
    func_8003E614(arg0);
    if (p[0x8F] == 0) {
        return 0;
    }
    idx = p[0x96];
    if (D_80073E00[idx] == 0) {
        func_801EB6E8(arg0);
        return 1;
    }
    p[0x8C] = 0;
    if (idx == 50) {
        func_8003AFF4((s32)arg0);
    } else if (idx == 5 || idx == 14) {
        func_8003BA04(arg0, 0x5C);
    }
    start_player_attack(arg0, 1);
    return 1;
}
