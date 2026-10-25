#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
extern struct X4_BackgroundObj background_objects[3];

void func_800F05C0(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xA) = 0x791;
    M2C_FIELD(arg0, s16*, 0xE) = 0xC9;
    if (background_objects[M2C_FIELD(arg0, s8*, 0x14)].x_pos.i.hi < 0x400) {
        M2C_FIELD(arg0, s16*, 0xA) = 0x191;
    }
    func_8002CCB0(arg0, 0x60, 0x10);
}
