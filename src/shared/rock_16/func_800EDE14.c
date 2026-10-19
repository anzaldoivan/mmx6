#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CB50();
extern s8 D_800CCEF7;
extern u16 D_800F111C[][2];
extern u8 D_800F1CF0[];

void func_800EDE14(void* arg0) {
    s32 i;
    u32 n;

    i = *((u8*)arg0 + 2) & 0xF;
    n = i & 0xFF;
    if (n >= 8) {
        n = 8;
    }
    if (n == D_800CCEF7 || D_800F1CF0[n] != 0) {
        *(u16*)((u8*)arg0 + 0xA) = D_800F111C[i][0];
        *(u16*)((u8*)arg0 + 0xE) = D_800F111C[i][1];
        ((void (*)())func_8002CB50)(arg0);
        return;
    }
    *((u8*)arg0 + 3) = 0;
}
