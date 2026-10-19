#include "common.h"
#define M2C_UNK s32

M2C_UNK func_801ECD54(void*, M2C_UNK);

#define ECED4_U16(o) (*(u16*)(p + (o)))
#define ECED4_S32(o) (*(s32*)(p + (o)))

void func_801ECED4(s8* p) {
    ((void (*)(void*, s32))func_801ECD54)(p, 0x23);
    if (p[0xD3] == 0) {
        if (ECED4_U16(0x7C) & 2) {
            p[0x15] = 0;
        }
        if (ECED4_U16(0x7C) & 1) {
            p[0x15] = 0x40;
        }
    }
    if (((u8*)p)[0x45] & 0x10) {
        ECED4_S32(0x24) = 0xFFFD0000;
        p[0x45] = 0;
        ECED4_S32(0x20) = 0;
        ECED4_S32(0x28) = 0;
        p[0x67] = -1;
        ECED4_S32(0x2C) = ECED4_S32(0x100);
        p[6]++;
    }
}

#undef ECED4_U16
#undef ECED4_S32
