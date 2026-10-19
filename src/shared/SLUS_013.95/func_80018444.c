#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80018524(u8);
extern s8 D_80097418;
extern u8 D_80097770;
extern u8 D_800A21B4;
extern s8 D_800CC869;
extern u8 D_800E2E14;
extern s8 D_800E2E16;
extern s32 D_800E2E18;
extern s32 D_800E2E4C;
extern u8 D_800E2E51;
extern s32 D_800E2E58;
extern s32 D_800E2E5C;
extern u8 D_800E2E60;

void func_80018444(void) {
    ((void (*)(u8))func_80018524)(0);
    D_800E2E58 = 0;
    D_800A21B4 = 0;
    D_80097770 = 0;
    D_800CC869 = 1;
    D_800E2E51 = 1;
    D_800E2E16 = 0;
    D_800E2E5C = 0;
    D_800E2E14 = 0x80;
    D_800E2E18 = 0;
    D_80097418 = 0;
    D_800E2E4C = 0;
    D_800E2E60 = 0;
}
