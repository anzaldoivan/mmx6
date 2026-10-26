#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);

void func_800EDCF4(void* arg0) {
    void* parent;
    s32 angle;
    s32 d;
    s32 a;
    s32 b;

    parent = M2C_FIELD(arg0, void**, 0x50);
    {
        // !FAKE: depin: dropping it breaks the match (69/73)
        register s32 py asm("$2") = M2C_FIELD(parent, s16*, 0xE);
        angle =
            ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                   M2C_FIELD(parent, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) * 0x10;
    M2C_FIELD(arg0, s32*, 0x24) = rsin(angle) * 0x10;
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    move_object(arg0);
    a = M2C_FIELD(parent, s16*, 0xA);
    b = M2C_FIELD(arg0, s16*, 0xA);
    d = a - b;
    if (d >= 0) {
        if (d < 3) {
            goto near_x;
        }
        return;
    }
    if (b - a < 3) {
    near_x:
        a = M2C_FIELD(parent, s16*, 0xE);
        b = M2C_FIELD(arg0, s16*, 0xE);
        d = a - b;
        if (d >= 0) {
            if (d < 3) {
                goto near_y;
            }
            return;
        }
        if (b - a < 3) {
        near_y:
            M2C_FIELD(parent, u8*, 0x7)--;
            M2C_FIELD(arg0, u8*, 0x6)++;
        }
    }
}
