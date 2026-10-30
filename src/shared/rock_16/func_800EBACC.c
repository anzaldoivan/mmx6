#include "common.h"

void* alloc_sprite_slot();
extern s8 D_800F0F2C[];
extern s8 D_800F0F34[];
extern u8 D_800F1CA9;
extern u8 D_800F1CF0[];

void func_800EBACC(u8* arg0) {
    s8 a;
    s8 b;
    u8* obj;

    if (D_800F1CA9 >= 9) {
        a = D_800F0F34[*(s16*)(arg0 + 0xA) * 2];
        b = D_800F0F34[*(s16*)(arg0 + 0xA) * 2 + 1];
    } else {
        a = D_800F0F2C[*(s16*)(arg0 + 0xA) * 2];
        b = D_800F0F2C[*(s16*)(arg0 + 0xA) * 2 + 1];
    }
    if (*(s16*)(arg0 + 8) == 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0xC;
            obj[2] = a | 0x40;
        }
        if (b != -1) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0xC;
                obj[2] = b | 0x40;
            }
        }
        D_800F1CF0[a] = 1;
        if (b != -1) {
            D_800F1CF0[b] = 1;
        }
    }
    if (++*(s16*)(arg0 + 8) >= 4) {
        *(s16*)(arg0 + 8) = 0;
        ++*(s16*)(arg0 + 0xA);
        if (D_800F1CA9 >= 9) {
            if (*(s16*)(arg0 + 0xA) >= 5) {
                goto block;
            }
            return;
        }
        if (*(s16*)(arg0 + 0xA) >= 4) {
        block:
            *(s16*)(arg0 + 0xA) = 0;
            arg0[2]++;
        }
    }
}
