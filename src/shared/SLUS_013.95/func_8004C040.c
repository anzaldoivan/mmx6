#include "common.h"
#include "mmx6/x4.h"

extern void (*D_80078250[])(struct X4_QuadObj*);
extern u8 D_80078240[];
extern s32 D_80097420;
extern u8 D_800E4478[0x10];

#define QUAD_FRAME(p) (*(u8*)((u8*)(p) + 0x3C))

void func_8004C040(struct X4_QuadObj* arg0) {
    D_80078250[arg0->unk5](arg0);
    if (arg0->unk5 != 0 && D_800E4478[0] != 0 && (u32)D_80097420 % 3 == 0) {
        arg0->unk34 = D_80078240[QUAD_FRAME(arg0)];
        QUAD_FRAME(arg0)++;
        if (QUAD_FRAME(arg0) == 0xE) {
            QUAD_FRAME(arg0) = 0;
        }
    }
}

#undef QUAD_FRAME
