#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
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
    if (d >= 0) {
        if (d < 2) {
            goto near_x;
        }
        return;
    }
    if (M2C_FIELD(self, s16*, 0xA) - M2C_FIELD(t, s16*, 0xA) < 2) {
    near_x:
        d = M2C_FIELD(t, s16*, 0xE) - M2C_FIELD(self, s16*, 0xE);
        if (d >= 0) {
            if (d < 2) {
                goto near_y;
            }
            return;
        }
        if (M2C_FIELD(self, s16*, 0xE) - M2C_FIELD(t, s16*, 0xE) < 2) {
        near_y:
            M2C_FIELD(t, u8*, 0x7)--;
            M2C_FIELD(self, u8*, 0x6)++;
        }
    }
}
