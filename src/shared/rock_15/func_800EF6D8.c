#include "common.h"
#define M2C_UNK s32

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);

void func_800EF6D8(void* arg0) {
    if (--FX(arg0, s16, 0x88) == 0) {
        func_80016C48(2, 0x88, arg0);
        if (FX(arg0, u8, 0x15) == 0) {
            FX(arg0, s32, 0x20) = 0xFFFA0000;
        } else {
            FX(arg0, s32, 0x20) = 0x60000;
        }
        FX(arg0, s32, 0x24) = 0;
        FX(arg0, u8, 0x6)++;
    }
}
