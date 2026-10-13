#include "common.h"
#define M2C_UNK s32
M2C_UNK func_8003F7BC(void*, M2C_UNK, M2C_UNK);

#define B(o) (*(s8*)((u8*)self + (o)))
#define UB(o) (*(u8*)((u8*)self + (o)))
#define W(o) (*(s32*)((u8*)self + (o)))

M2C_UNK func_8003DF58(void* self) {
    u8 t;
    register s32 k asm(
        "$6"); // !FAKE: depin: dropping it breaks the match (62/69)

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
