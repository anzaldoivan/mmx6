#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
void func_800F6A1C(void* arg0, s32 arg1);

void func_800F50EC(void* arg0) {
    s8 mode = ((s8*)arg0)[0x45];
    u8 r;

    if (mode == 1) {
        r = (u32)func_8002D2D4() % 3;
        if (r != mode) {
            switch (r) {
            case 0:
                func_80016C48(2, 0x22, arg0);
                break;
            case 1:
                break;
            case 2:
                goto two;
            }
        } else {
            func_80016C48(2, 0x23, arg0);
            if (0) {
            two:
                func_80016C48(2, 0x24, arg0);
            }
        }
        func_80016C48(2, 0x5D, arg0);
        func_800F6A1C(arg0, 0);
    } else if (mode == 2) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 6);
        ((u8*)arg0)[6]++;
    }
}
