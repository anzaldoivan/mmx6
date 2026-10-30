#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern struct X4_PlayerObj g_Player;

void func_800F3A2C(void* arg0) {
    u16 px;
    u16 py;
    s32 ang;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        play_sound(2, 0x13, arg0);
        set_animation(arg0, 0xA);
        {
            // !FAKE: depin: dropping it breaks the match (57/63)
            register struct X4_PlayerObj* pl asm("$2") = &g_Player;
            px = pl->x_pos.u.hi;
            M2C_FIELD(arg0, u16*, 0x84) = px;
            py = pl->y_pos.u.hi;
            M2C_FIELD(arg0, u16*, 0x86) = py;
            ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - (s16)py,
                         (s16)px - M2C_FIELD(arg0, s16*, 0xA));
        }
        {
            s32 w = rcos(ang);
            s32 e = w << 4;
            M2C_FIELD(arg0, s32*, 0x20) = ((w << 5) + e) << 1;
        }
        {
            s32 w = rsin(ang);
            s32 e = w << 4;
            M2C_FIELD(arg0, s32*, 0x24) = ((w << 5) + e) << 1;
        }
        if (M2C_FIELD(arg0, s32*, 0x20) >= 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
