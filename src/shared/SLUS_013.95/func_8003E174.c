#include "common.h"
#define M2C_UNK s32
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 check_giga_attack(void* self);
void func_8003E614(void* arg0);
M2C_UNK func_8003F864(void*, M2C_UNK);
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
    func_8003F864(self, 1);
    return 1;
}

#undef B
