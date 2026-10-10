#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D230(void*);
extern s16 D_80097214;
extern s16 D_80097216;

void func_800F59C0(void* arg0) {
    u8* p = arg0;

    ((void (*)(void*))func_8002D230)(p);
    if (*(u8*)(p + 0x15) == 0) {
        if (*(s16*)(p + 0xA) < (D_80097216 + 0x30)) {
            *(s32*)(p + 0x24) = 0x20000;
            *(s32*)(p + 0x2C) = -0x6000;
            *(s32*)(p + 0x20) = -0x10000;
            *(u8*)(p + 6) += 1;
        }
    } else if ((D_80097214 + 0x110) < *(s16*)(p + 0xA)) {
        *(s32*)(p + 0x24) = 0x20000;
        *(s32*)(p + 0x2C) = -0x6000;
        *(s32*)(p + 0x20) = 0x10000;
        *(u8*)(p + 6) += 1;
    }
}
