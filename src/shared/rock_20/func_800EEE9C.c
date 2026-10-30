#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_800CCEF6;
extern u8 D_800F366C[];

void func_800EEE9C(u8* arg0) {
    s32 i;
    u8* t = D_800F366C + 4;
    i = D_800CCEF6 - 1;
    ((void (*)(s32, s32, s32))open_text_box)(*(u16*)(t + i * 6), 0xFF, 0);
    arg0[2]++;
}
