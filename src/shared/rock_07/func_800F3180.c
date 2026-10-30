#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F6C70(void*, s16, s16, s16);
extern struct X4_PlayerObj g_Player;

void func_800F3180(void* arg0) {
    s16 x;
    s16 y;
    s32 ang;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        x = M2C_FIELD(arg0, s16*, 0xA);
        y = M2C_FIELD(arg0, s16*, 0xE);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            x -= 0x10;
        } else {
            x += 0x10;
        }
        y += 0x34;
        do {
            ang = ratan2(y - g_Player.y_pos.i.hi, g_Player.x_pos.i.hi - x);
            play_sound(2, 0x63, arg0);
        } while (0);
        {
            // !FAKE: depin: dropping it breaks the match (66/68)
            register void* a asm("$4") = arg0;
            func_800F6C70(a, ang - 0x1C7, x, y);
        }
        func_800F6C70(arg0, ang, x, y);
        func_800F6C70(arg0, ang + 0x1C7, x, y);
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
