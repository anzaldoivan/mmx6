#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK D_800970A0;
void func_8002AF6C(s32 arg0, s32 mask);

void func_8002B29C(void) {
    struct X4_PlayerObj* p = &D_800970A0;

    if (((u8*)p)[0xE4] & 1) {
        ((void (*)())func_8002AF6C)(1);
    }
    if (((u8*)p)[0xE4] & 2) {
        ((void (*)())func_8002AF6C)(2);
    }
}
