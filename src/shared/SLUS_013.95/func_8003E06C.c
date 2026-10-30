#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 check_giga_attack(void* self);
void func_8003E614(void* arg0);
M2C_UNK func_8003F864(void*, M2C_UNK);
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
    func_8003F864(arg0, 1);
    return 1;
def:
    ((void (*)(void*, s32))func_8003F864)(arg0, 0);
    return 1;
}
#undef B
