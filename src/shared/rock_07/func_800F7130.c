// rolefeed (3.1 T4): func_800F7130 of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))
#define OP(p, o) (*(void**)((u8*)(p) + (o)))

extern struct X4_PlayerObj g_Player;
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
    dx = g_Player.x_pos.i.hi;
    dy = g_Player.y_pos.i.hi;
    angle = ratan2(OH(arg0, 0xE) - dy, dx - OH(arg0, 0xA));
    OW(arg0, 0x20) = rcos(angle) << 6;
    OW(arg0, 0x24) = rsin(angle) << 6;
    OW(arg0, 0x28) = 0;
    OW(arg0, 0x2C) = 0;
    OUB(arg0, 0x6) = OUB(arg0, 0x6) + 1;
}
