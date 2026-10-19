#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_80044238(struct X4_WeaponObj* arg0) {
    if ((F_U8(arg0->owner, 0x8D) >> (arg0->unk2 - 1)) & 1) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 5);
        arg0->on_screen = 1;
        arg0->unk5++;
    }
}
