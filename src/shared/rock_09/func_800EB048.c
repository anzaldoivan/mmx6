#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

void func_800EB284();
extern s16 D_800970AE;

void func_800EB048(void* arg0) {
    s32 g;
    s16 temp_a1;

    g = D_800970AE;
    temp_a1 = M2C_FIELD(SPAD4C, s16*, 0x82);
    if ((g - M2C_FIELD(arg0, s16*, 0xE)) >= temp_a1) {
        M2C_FIELD(arg0, u8*, 0x16) = 0x12;
        func_800EB284(arg0, temp_a1);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}
