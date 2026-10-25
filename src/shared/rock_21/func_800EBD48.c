#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

void func_800EBD48(void* arg0) {
    s32 var_v0;
    u16 temp_v0;

    if ((u32)(M2C_FIELD(arg0, u16*, 4) - 0x1E) >= 0x385U) {
        background_objects[0].unk3 = 0;
    } else {
        background_objects[0].unk3 = 1;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0x3C0) {
        M2C_FIELD(arg0, u16*, 4) = 0;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        background_objects[0].x_pos.i.hi = 0xC00;
        background_objects[0].unk4C = 1;
        M2C_FIELD(arg0, u8*, 1) = M2C_FIELD(arg0, u8*, 1) + 1;
    }
}
