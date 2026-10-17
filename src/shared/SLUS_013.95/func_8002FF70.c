#include "common.h"
#include "mmx6/x4.h"

s32 func_80028078(s32, s32, u32);

#define D_1F800008 (*(u8**)0x1F800008)
#define D_1F80000C (*(u8**)0x1F80000C)

s32 func_8002FF70(void* arg0) {
    struct X4_MainObj* obj = arg0;
    u8* p = (u8*)obj->terrain_box;
    u32 a = obj->x_pos.u.hi << 16;
    u32 b = (u16)(obj->y_pos.i.hi + (s8)p[1] + p[3] - 1) << 16;
    s32 x = (s32)a >> 24;
    s32 y = (s32)b >> 24;
    s32 sx = (a >> 20) & 0xF;
    s32 sy = (b >> 20) & 0xF;
    s32 ret;
    s32 v;

    ret = func_80028078(obj->bg_offset, x, y);
    if (ret == 0 || y < 0) {
        v = 0;
    } else if (x < 0) {
        v = 0;
    } else {
        v = D_1F80000C[(*(u16*)(D_1F800008 + ret * 512 + sy * 32 + sx * 2) &
                        0x3FFF) *
                       4];
    }
    if (v == 0x3B) {
        v = 0x38;
    }
    return v;
}
#undef D_1F800008
#undef D_1F80000C
