#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80031DA8();
extern u8 D_80097185;
extern void (*D_800F7060[])(s8*);

void func_800F1A5C(s8* arg0) {
    s8* temp_s1;
    s32 temp_v0;

    temp_s1 = *(s8**)(arg0 + 0x7C);
    D_800F7060[arg0[6]](arg0);
    if (arg0[6] < 3) {
        return;
    }
    if (D_80097185 != 0) {
        return;
    }
    func_80031DA8(arg0);
    if (arg0[6] >= 8) {
        return;
    }
    temp_v0 = (*(u16*)(arg0 + 0x8E))++;
    if ((s16)temp_v0 > 0x1E0) {
        temp_v0 = (*(u16*)(arg0 + 0x8E))++;
        arg0[3] ^= 1;
        if ((s16)temp_v0 > 0x21C) {
            *(s32*)(arg0 + 0x68) = 0;
            *(s32*)(arg0 + 0x54) = 0;
            temp_s1[0x8A] = 0;
        }
        temp_v0 = (*(u16*)(arg0 + 0x8E))++;
        if ((s16)temp_v0 > 0x258) {
            if (temp_s1[0x8D] != 0) {
                temp_s1[0x8D]--;
            }
            arg0[4] = 2;
        }
    } else if (*(s16*)(arg0 + 0x90) == (s16) * (u16*)(arg0 + 0x8E)) {
        arg0[7] = arg0[6];
        arg0[0x93] = 0;
        arg0[6] = 8;
    }
}
