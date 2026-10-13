#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
extern s32 D_80078908;
extern s32 D_8007890C;
extern s32 D_80078914;
extern s32 D_80078918;

void func_8004FC40(u8* arg0) {
    arg0[0x5C] = 0xD;
    arg0[0x60] = 6;
    if (arg0[0x84] == 0) {
        arg0[0x81] = 0x3C;
        *(s32**)(arg0 + 0x54) = &D_8007890C;
        *(s32**)(arg0 + 0x50) = &D_80078908;
        if (arg0[0x7E] == 0) {
            if (arg0[0x82] == 0) {
                func_800179A4(arg0, 0x13);
            } else {
                func_800179A4(arg0, 0x14);
            }
        } else if (arg0[0x82] == 0) {
            func_800179A4(arg0, 0x15);
        } else {
            func_800179A4(arg0, 0x16);
        }
    } else {
        arg0[0x81] = 0x14;
        *(s32**)(arg0 + 0x54) = &D_80078918;
        *(s32**)(arg0 + 0x50) = &D_80078914;
        if (arg0[0x82] == 0) {
            func_800179A4(arg0, 0x1C);
        } else {
            func_800179A4(arg0, 0x23);
        }
    }
    arg0[5]++;
}
#undef func_800179A4
