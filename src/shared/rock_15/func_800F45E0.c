#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D2D4();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_800F6F34;

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800F45E0(void* arg0) {
    s32 angle;
    u8 r;

    F(void*, 0x68) = &D_800F6F34;
    r = (u32)func_8002D2D4() % 5;
    angle = func_80065B74((s16)(D_800971F8[0].unk2A + 0x70) - F(s16, 0xE),
                          (s16)(D_800971F8[0].unk26 + (r << 5) + 0x10) -
                              F(s16, 0xA));
    F(s32, 0x20) = func_80065A14(angle) << 6;
    F(s32, 0x24) = -func_80065944(angle) << 6;
    F(s16, 0x8C) = 0;
    F(u8, 7) = 1;
    F(u8, 6)++;
}

#undef F
