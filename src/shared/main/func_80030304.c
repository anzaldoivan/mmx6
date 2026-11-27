#include "common.h"
#include "mmx6/x4.h"

s32 func_80028078(s32, s32, u32);

#define SCR_08 (*(s32*)0x1F800008)
#define SCR_0C (*(s32*)0x1F80000C)

u8 func_80030304(struct X4_PlayerObj* self, s16 x, s16 y) {
    s32 xi;
    s32 yi;
    s32 col;
    s32 row;
    s32 t;
    u8 r;

    xi = x >> 8;
    yi = y >> 8;
    col = (u32)(x & 0xF0) >> 4;
    row = (u32)(y & 0xF0) >> 4;
    t = func_80028078(self->bg_offset, xi, yi);
    if (t == 0 || yi < 0 || xi < 0) {
        r = 0;
    } else {
        self->unk6C = x & 0xF;
        self->unk6E = y & 0xF;
        r = *(u8*)(((*(u16*)((col << 1) + ((row << 5) + ((t << 9) + SCR_08))) &
                     0x3FFF)
                    << 2) +
                   SCR_0C);
    }
    if (r == 0x3B) {
        r = 0x38;
    }
    return r;
}
#undef SCR_08
#undef SCR_0C
