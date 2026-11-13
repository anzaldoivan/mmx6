#include "common.h"

s32 get_tile_attr_above(void*);

s32 func_8003040C(u8* p) {
    s32 r = get_tile_attr_above(p);

    switch (r) {
    case 0x28:
    case 0x29:
    case 0x2D:
        if (*(s16*)(p + 0x6E) >= 8) {
            r = 0;
        }
        break;
    case 0x27:
    case 0x2A:
        if ((u16) * (s16*)(p + 0x6E) - 2U >= 9) {
            r = 0;
        }
        break;
    case 0x26:
    case 0x2B:
        if ((u16) * (s16*)(p + 0x6E) - 6U >= 9) {
            r = 0;
        }
        break;
    case 0x25:
    case 0x2C:
        if (*(s16*)(p + 0x6E) < 8) {
            r = 0;
        }
        break;
    }
    return r;
}
