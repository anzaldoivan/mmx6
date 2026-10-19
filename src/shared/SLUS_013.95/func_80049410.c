#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002C9B0();
extern struct X4_PlayerObj D_800970A0;
extern void (*D_80077BE8[])(void*, struct X4_PlayerObj*);

void func_80049410(void* arg0) {
    if (D_800970A0.unk5 == 0x14) {
        ((void (*)())func_8002C9B0)(arg0, &D_800970A0);
        return;
    }
    D_80077BE8[((s8*)arg0)[4]](arg0, &D_800970A0);
}
