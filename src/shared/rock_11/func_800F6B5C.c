// rolefeed (3.1 T4): func_800F6B5C of src/rock_11/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#undef D_800FDA7C

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void move_object();
s32 random_byte();
extern struct X4_PlayerObj g_Player;

void func_800F6B5C(void* arg0) {
    s32 angle;
    s32 v;
    s32 t;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        s16 px = g_Player.x_pos.i.hi;
        s16 py = g_Player.y_pos.i.hi;
        angle = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                       px - M2C_FIELD(arg0, s16*, 0xA));
        v = rcos(angle);
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x20) = ((v * 32 + t) << 1) / 4;
        v = rsin(angle);
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x24) = ((v * 32 + t) << 1) / 4;
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x24) * 2;
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x20) * 2;
        }
        move_object(arg0);
        v = M2C_FIELD(arg0, s32*, 0x20);
        if (v >= 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u16*, 0x7C) = ((u32)random_byte() % 40 & 0xFF) + 0x32;
        M2C_FIELD(arg0, u8*, 0x5)++;
    }
}
