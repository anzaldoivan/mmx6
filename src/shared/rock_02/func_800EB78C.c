#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800EB78C(u8* arg0) {
    s32 n;
    s32 i;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[5] = 2;
        arg0[6] = 0;
        if (*(s8*)(arg0 + 7) == 0) {
            *(s32*)(arg0 + 0x28) = 0xC00;
            set_animation(arg0, 0);
            arg0[7] = 0x40;
            switch (arg0[0x80]) {
            case 0:
                n = 4;
                break;
            case 1:
                n = 8;
                break;
            case 2:
                n = 0xC;
                break;
            case 3:
                n = 0x10;
                break;
            case 4:
                n = 0x14;
                break;
            case 5:
                n = 0x18;
                break;
            case 6:
                n = 0x1C;
                break;
            case 7:
                n = 0;
                break;
            }
            for (i = 0; i < n; i++) {
                func_80017A04(arg0);
            }
        } else {
            *(s32*)(arg0 + 0x28) = -0xC00;
            set_animation(arg0, 2);
            arg0[7] = 0;
            switch (arg0[0x80]) {
            case 0:
                n = 0;
                break;
            case 1:
                n = 0x1C;
                break;
            case 2:
                n = 0x18;
                break;
            case 3:
                n = 0x14;
                break;
            case 4:
                n = 0x10;
                break;
            case 5:
                n = 0xC;
                break;
            case 6:
                n = 8;
                break;
            case 7:
                n = 4;
                break;
            }
            for (i = 0; i < n; i++) {
                func_80017A04(arg0);
            }
        }
    }
}
