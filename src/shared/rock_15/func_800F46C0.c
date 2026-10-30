#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 random_byte();

void func_800F46C0(u8* arg0) {
    ((void (*)(void*))func_80017A04)(arg0);
    if (*(s8*)(arg0 + 0x45) == 1) {
        arg0[7] = 0xA;
        *(s32*)(arg0 + 0x28) = 0;
        *(s16*)(arg0 + 0x8C) = 0x30;
        *(s16*)(arg0 + 0x8E) = 0;
        arg0[0x92] = 0;
        if (!(random_byte() & 1)) {
            *(s32*)(arg0 + 0x20) = 0x20000;
            arg0[6] = arg0[6] + 1;
        } else {
            *(s32*)(arg0 + 0x20) = -0x20000;
            arg0[6] = arg0[6] + 2;
        }
    }
}
