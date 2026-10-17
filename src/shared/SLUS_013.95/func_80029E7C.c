#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800CCF38;

s32 func_80029E7C(struct X4_StageObjectRecord* rec, s16 arg1, s16 arg2,
                  s16 arg3) {
    u32 n;
    u8 g;
    u8 t;
    s32 hi;

    n = rec->object_type & 0xF;
    if (n >= 3 || (g = D_800CCF38) == 3) {
        return 0;
    }
    if (g < n) {
        return 1;
    }
    t = rec->object_type;
    hi = t & 0xF0;
    switch (hi) {
    case 0:
        rec->object_type = t + 0x10;
        return 0;
    case 0x20:
        rec->object_type = t + 0x10;
        return 1;
    case 0x40:
        if (g == 0) {
            return 1;
        }
        rec->object_type = (t & 0xF) + 0x10;
        return 0;
    case 0x60:
        if (g == 0) {
            return 1;
        }
        rec->object_type = (t & 0xF) + 0x30;
        return 1;
    }
    return 1;
}
