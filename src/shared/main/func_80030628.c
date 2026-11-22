#include "common.h"

extern u8 D_800E4191;
extern s16 D_800E41A2;

s32 func_80030628(u8* arg0, u8 arg1) {
    switch (arg1) {
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3C:
    case 0x3E:
    case 0x3F:
        D_800E4191 |= 2;
        D_800E41A2 = 0x10 - *(u16*)(arg0 + 0x6C);
        return -1;
    }
    return 0;
}
