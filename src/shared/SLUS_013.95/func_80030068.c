#include "common.h"
#include "mmx6/x4.h"

s32 func_80028078(s32, s32, u32);

#define SCR_08 (*(s32*)0x1F800008)
#define SCR_0C (*(s32*)0x1F80000C)

s32 func_80030068(void* arg0) {
    struct X4_MainObj* self = arg0;
    struct X4_Unk_unk68* box = self->terrain_box;
    u32 a = self->x_pos.u.hi << 16;
    u32 b = (u16)(self->y_pos.u.hi + box->unk1 + box->unk3) << 16;
    s32 x = (s32)a >> 24;
    s32 y = (s32)b >> 24;
    s32 sx = (a >> 20) & 0xF;
    s32 sy = (b >> 20) & 0xF;
    s32 t;
    u8 r;

    t = func_80028078(self->bg_offset, x, y);
    if (t == 0 || y < 0) {
        r = 0;
    } else if (x < 0) {
        r = 0;
    } else {
        r = *(u8*)(((*(u16*)((sx << 1) + ((sy << 5) + ((t << 9) + SCR_08))) &
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
