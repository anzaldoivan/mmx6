#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_800E9F7C(void);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800FAB00(s8* p) {
    s32 t;

    t = (u16)D_800CF854 - 1;
    D_800CF854 = t;
    D_80097430 -= 0x20;
    D_80090D5C -= 0x400;
    if ((u16)t == 0) {
        func_800E9F7C();
        func_80016C48(0, 2, 0);
        *(s16*)(p + 8) = 0x15;
        *(s16*)(p + 0xA) = 1;
        p[1]++;
    }
}
