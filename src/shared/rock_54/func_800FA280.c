#include "common.h"
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

void func_800FA280(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 4) >= 0x78) {
        background_objects[0].unk3 = 1;
        background_objects[0].x_pos.u.hi = 0;
        background_objects[0].y_pos.u.hi = 0;
        background_objects[0].unk4C = 1;
        M2C_FIELD(arg0, u8*, 1)++;
        return;
    }
    M2C_FIELD(arg0, s16*, 4)++;
}
