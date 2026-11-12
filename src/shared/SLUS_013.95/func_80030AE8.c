#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800E4191;
extern s16 D_800E41A2;
extern s16 D_800E41A4;
extern u8 D_80097187;

s32 func_80030AE8(struct X4_PlayerObj* arg0, u8 arg1, s32 arg2) {
    if (arg2 == 0) {
        switch (arg1) {
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3C:
            return -1;
        case 0x3E:
        case 0x3F:
            if (D_80097187 != 2) {
                arg0->touching_spikes = 1;
            }
            return -1;
        }
        return 0;
    } else {
        switch (arg1) {
        case 0x21:
        case 0x22:
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3C:
            return -1;
        case 0x3E:
        case 0x3F:
            if (D_80097187 != 2) {
                arg0->touching_spikes = 1;
            }
            return -1;
        }
    }
    return 0;
}
