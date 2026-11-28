// rolefeed (3.1 T4): func_800F65D8 of src/rock_11/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void move_object();
extern struct X4_PlayerObj g_Player;

void func_800F65D8(void* arg0) {
    s32 angle;
    s32 d;

    {
        s16 px = g_Player.x_pos.i.hi;
        s16 py = g_Player.y_pos.i.hi;
        angle = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                       px - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) << 5;
    M2C_FIELD(arg0, s32*, 0x24) = rsin(angle) << 5;
    move_object(arg0);
    d = g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA);
    if (d >= 0 ? d >= 4
               : M2C_FIELD(arg0, s16*, 0xA) - g_Player.x_pos.i.hi >= 4) {
        if (M2C_FIELD(arg0, s32*, 0x20) >= 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
