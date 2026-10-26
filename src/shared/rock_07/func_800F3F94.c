#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern struct X4_PlayerObj g_Player;
extern s32 D_800F97A0;

void func_800F3F94(void* arg0) {
    struct X4_PlayerObj* p;
    s32 ang;
    s32 t;
    s32 pad[4];

    if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
        M2C_FIELD(arg0, void**, 0x50) = &D_800F97A0;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s16*, 0x88) = 0x22;
        M2C_FIELD(arg0, u8*, 0x6)++;
        return;
    }
    p = &g_Player;
    {
        s32 px = p->x_pos.i.hi;
        s32 py = p->y_pos.i.hi;
        ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                     px - M2C_FIELD(arg0, s16*, 0xA));
    }
    switch (M2C_FIELD(arg0, u8*, 0x2) & 0xF) {
    case 0:
        M2C_FIELD(arg0, s32*, 0x20) = (rcos(ang) * 16) >> 1;
        M2C_FIELD(arg0, s32*, 0x24) = (rsin(ang) * 16) >> 1;
        break;
    case 1:
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) * 16;
        M2C_FIELD(arg0, s32*, 0x24) = rsin(ang) * 16;
        break;
    case 2:
        t = rcos(ang) * 16;
        M2C_FIELD(arg0, s32*, 0x20) = ((t << 1) + t) >> 1;
        t = rsin(ang) * 16;
        M2C_FIELD(arg0, s32*, 0x24) = ((t << 1) + t) >> 1;
        break;
    case 3:
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) * 32;
        M2C_FIELD(arg0, s32*, 0x24) = rsin(ang) * 32;
        break;
    }
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    move_object(arg0);
}
