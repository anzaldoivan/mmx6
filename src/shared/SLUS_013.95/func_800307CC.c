#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800E4191;
extern s16 D_800E41A2;
extern s16 D_800E41A4;
extern u8 D_80097187;

s32 func_800307CC(struct X4_PlayerObj* arg0, u8 arg1) {
    switch (arg1) {
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3C:
    case 0x3E:
    case 0x3F:
        D_800E4191 |= 4;
        D_800E41A4 = 0x10 - arg0->unk6E;
        return -1;
    }
    return 0;
}
