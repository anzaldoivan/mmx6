#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_80065B74(s32, s32);
void func_800F6C70(void*, s16, s16, s16);
extern struct X4_PlayerObj D_800970A0;

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
            ang = func_80065B74(y - D_800970A0.y_pos.i.hi,
                                D_800970A0.x_pos.i.hi - x);
            func_80016C48(2, 0x63, arg0);
        } while (0);
        {
            register void* a asm("$4") = arg0;
            func_800F6C70(a, ang - 0x1C7, x, y);
        }
        func_800F6C70(arg0, ang, x, y);
        func_800F6C70(arg0, ang + 0x1C7, x, y);
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
