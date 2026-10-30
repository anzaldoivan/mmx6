#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object();
void func_800EABA4(struct X4_MainObj*);
extern struct X4_PlayerObj g_Player;

void func_800EA84C(void* arg0) {
    s32 angle;
    s32 v;
    s32 t;

    s16 px = g_Player.x_pos.i.hi;
    s16 py = g_Player.y_pos.i.hi;
    angle = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                   px - M2C_FIELD(arg0, s16*, 0xA));
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    v = rcos(angle);
    t = v * 16;
    M2C_FIELD(arg0, s32*, 0x20) = v * 32 + t;
    v = rsin(angle);
    t = v * 16;
    M2C_FIELD(arg0, s32*, 0x24) = v * 32 + t;
    move_object(arg0);
    v = M2C_FIELD(arg0, s32*, 0x24);
    if (v > 0) {
        set_animation(arg0, 1);
    } else {
        set_animation(arg0, 2);
    }
    func_800EABA4(arg0);
    M2C_FIELD(SPAD, s32*, 0x84) = angle;
    M2C_FIELD(arg0, u8*, 0x6)++;
}
