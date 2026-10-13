#include "common.h"
#include "mmx6/x4.h"

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))
#define OP(p, o) (*(void**)((u8*)(p) + (o)))

s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj D_800970A0;
extern s32 D_800F977C;
extern s32 D_800F9780;
extern s32 D_800F9784;

void func_800F7130(void* arg0) {
    s32 angle;
    s32 dx;
    s32 dy;

    OP(arg0, 0x54) = &D_800F977C;
    OP(arg0, 0x50) = &D_800F9780;
    OP(arg0, 0x68) = &D_800F9784;
    dx = D_800970A0.x_pos.i.hi;
    dy = D_800970A0.y_pos.i.hi;
    angle = func_80065B74(OH(arg0, 0xE) - dy, dx - OH(arg0, 0xA));
    OW(arg0, 0x20) = func_80065A14(angle) << 6;
    OW(arg0, 0x24) = func_80065944(angle) << 6;
    OW(arg0, 0x28) = 0;
    OW(arg0, 0x2C) = 0;
    OUB(arg0, 0x6) = OUB(arg0, 0x6) + 1;
}
