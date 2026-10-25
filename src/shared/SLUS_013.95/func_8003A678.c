#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
M2C_UNK func_8003D10C(void*); /* extern */

void func_8003A678(void* arg0) {
    s16 d;
    s32 var_a2;
    s32 t;

    var_a2 = 0;
    t = M2C_FIELD(arg0, u16*, 0xA) - 0x40;
    d = t - background_objects[M2C_FIELD(arg0, s8*, 0x14)].x_pos.i.hi;
    if (d != 0) {
        if (d > 0) {
            M2C_FIELD(arg0, s8*, 0x15) = 0;
            var_a2 = d < 3;
        } else {
            M2C_FIELD(arg0, s8*, 0x15) = 0x40;
            if (d >= -2) {
                var_a2 = 1;
            }
        }
    } else {
        var_a2 = 1;
    }
    if (var_a2 != 0) {
        func_8003D10C(arg0);
        {
            u16 x = background_objects[M2C_FIELD(arg0, s8*, 0x14)].x_pos.u.hi;
            M2C_FIELD(arg0, s8*, 0xD0) = -1;
            M2C_FIELD(arg0, s8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s8*, 0x5) = 0x14;
            M2C_FIELD(arg0, s16*, 0xA) = x + 0x40;
        }
    }
}
