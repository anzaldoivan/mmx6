#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F0884(struct X4_MainObj* arg0) {
    arg0->sprite_frames =
        (const u8*)(SPAD20 + *(s32*)(func_8002A47C(arg0->id) * 4 + SPAD20));
    ((void (*)(void*, s32))func_800179A4)(arg0, 0);
    arg0->unk7 = 0;
    arg0->unk6++;
}
