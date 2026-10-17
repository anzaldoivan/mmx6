#include "common.h"
#include "mmx6/x4.h"

s32 func_80028078(s32, s32, u32);

#define SCR_08 (*(u8**)0x1F800008)
#define SCR_0C (*(u8**)0x1F80000C)

s32 func_8002FD3C(void* arg0) {
    struct X4_MainObj* obj = arg0;
    u8* p = (u8*)obj->terrain_box;
    u32 a = obj->x_pos.u.hi << 16;
    u32 b = (u16)(obj->y_pos.u.hi + (s8)p[1] - p[3]) << 16;
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
        v = SCR_0C[(*(u16*)(SCR_08 + ret * 512 + sy * 32 + sx * 2) & 0x3FFF) *
                   4];
    }
    if (v == 0x3B) {
        v = 0x38;
    }
    return v;
}
#undef SCR_08
#undef SCR_0C
