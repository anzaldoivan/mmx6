#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8003C4EC(struct X4_PlayerObj* self);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);

M2C_UNK func_8003F0BC(void* arg0) {
    s8 v;

    func_8003C4EC(arg0);
    v = ((s8*)arg0)[0x93];
    if (v == 1) {
        player_spawn_visual(1, 0x1B, 0, 0);
    } else if (v == 6) {
        player_spawn_visual(1, 0x1B, 0xA, 0);
    } else if (v == 8) {
        player_spawn_visual(1, 0x1B, 0xC, 0);
    }
}

#include "common.h"
#define M2C_UNK s32
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 check_giga_attack(void* self);
void func_8003E614(void* arg0);
M2C_UNK start_player_attack(void*, M2C_UNK);
extern s8 D_80073E00[];

#define B(o) (*(s8*)((u8*)self + (o)))

s32 func_8003F13C(void* self) {
    s8 t;

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
    B(0x84) = 0;
    B(0x86) = 0;
    B(0x8C) = 0;
    if (t == 5 || t == 0xE) {
        func_8003BA04(self, 0x58);
    }
    start_player_attack(self, 0);
    return 1;
}

#undef B
