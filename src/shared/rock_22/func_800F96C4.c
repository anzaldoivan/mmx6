#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);

void func_800F96C4(void* arg0) {
    s8 v;

    ((void (*)(void))func_80017A04)();
    if (*(s16*)((u8*)arg0 + 0x7C) != 0) {
        ((void (*)(void*))func_8002D2B0)(arg0);
        *(s16*)((u8*)arg0 + 0x7C) -= 1;
        return;
    }
    v = *(s8*)((u8*)arg0 + 0x45);
    if (v == 0) {
        func_800179A4(arg0, 0x2A);
    } else if (v == 1) {
        func_800179A4(arg0, 0x2B);
    } else if (v == 2) {
        func_800179A4(arg0, 0x2C);
    } else if (v == 3) {
        func_800179A4(arg0, 0x2D);
    }
    func_80016C48(2, 0x6B, arg0);
    *((u8*)arg0 + 6) += 1;
}
