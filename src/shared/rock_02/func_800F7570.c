#include "common.h"
#define M2C_UNK s32

#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
extern M2C_UNK D_8007433C;

void func_800F7570(u8* arg0) {
    u8* sp = SPAD4C;
    s32 f = 0;
    u8 b = sp[0x8A];

    if (!(b & 1)) {
        f = *(s8*)(sp + 0x8D) == 0;
    }
    if (!(b & 0x10) && *(s8*)(sp + 0x8E) == 0) {
        f = 1;
    }
    if (f != 0) {
        *(s32**)(arg0 + 0x58) = &D_8007433C;
        SPAD4C[0x8B] = 0x3C;
        arg0[5] = 0xC;
        arg0[6] = 0;
        return;
    }
    func_800179A4(arg0, 7);
    *(s16*)(arg0 + 0x7C) = 0;
    {
        register s32 t asm("$2") = arg0[6] + 1;
        arg0[6] = t;
    }
}
