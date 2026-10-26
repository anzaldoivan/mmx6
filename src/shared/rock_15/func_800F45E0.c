#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

s32 func_8002D2D4();
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F6F34;

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800F45E0(void* arg0) {
    s32 angle;
    u8 r;

    F(void*, 0x68) = &D_800F6F34;
    r = (u32)func_8002D2D4() % 5;
    angle = ratan2((s16)(background_objects[0].unk2A + 0x70) - F(s16, 0xE),
                   (s16)(background_objects[0].unk26 + (r << 5) + 0x10) -
                       F(s16, 0xA));
    F(s32, 0x20) = rcos(angle) << 6;
    F(s32, 0x24) = -rsin(angle) << 6;
    F(s16, 0x8C) = 0;
    F(u8, 7) = 1;
    F(u8, 6)++;
}

#undef F
