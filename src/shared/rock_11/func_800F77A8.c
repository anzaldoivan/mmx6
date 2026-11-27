// rolefeed (3.1 T4): func_800F77A8 of src/rock_11/E9860.c
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

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void move_object();
s32 random_byte();

void func_800F77A8(void* self) {
    void* t;
    s32 ang;
    s32 d;
    s32 v;
    s32 w;

    t = M2C_FIELD(self, void**, 0x50);
    if (--M2C_FIELD(self, s16*, 0x56) == 0) {
        M2C_FIELD(self, u16*, 0x56) = (random_byte() & 7) + 5;
        M2C_FIELD(self, s16*, 0x58) = (u8)((u32)random_byte() % 3);
    }
    v = M2C_FIELD(t, s16*, 0xA);
    w = M2C_FIELD(t, s16*, 0xE);
    ang =
        ratan2(M2C_FIELD(self, s16*, 0xE) - w, v - M2C_FIELD(self, s16*, 0xA));
    switch (M2C_FIELD(self, s16*, 0x58)) {
    case 0:
    default:
        M2C_FIELD(self, s32*, 0x20) = rcos(ang) * 16 / 3;
        M2C_FIELD(self, s32*, 0x24) = rsin(ang) * 16 / 3;
        break;
    case 1:
        v = rcos(ang) * 16;
        M2C_FIELD(self, s32*, 0x20) = v / 4;
        w = rsin(ang) * 16;
        M2C_FIELD(self, s32*, 0x24) = w / 4;
        break;
    case 2:
        M2C_FIELD(self, s32*, 0x20) = rcos(ang) * 16 / 6;
        M2C_FIELD(self, s32*, 0x24) = rsin(ang) * 16 / 6;
        break;
    }
    if (M2C_FIELD(self, s32*, 0x20) < 0) {
        M2C_FIELD(self, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(self, u8*, 0x15) = 0x40;
    }
    move_object(self);
    d = M2C_FIELD(t, s16*, 0xA) - M2C_FIELD(self, s16*, 0xA);
    if (d >= 0 ? d < 2
               : M2C_FIELD(self, s16*, 0xA) - M2C_FIELD(t, s16*, 0xA) < 2) {
        d = M2C_FIELD(t, s16*, 0xE) - M2C_FIELD(self, s16*, 0xE);
        if (d >= 0 ? d < 2
                   : M2C_FIELD(self, s16*, 0xE) - M2C_FIELD(t, s16*, 0xE) < 2) {
            M2C_FIELD(t, u8*, 0x7)--;
            M2C_FIELD(self, u8*, 0x6)++;
        }
    }
}
