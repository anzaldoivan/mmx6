#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EBE74(void* self) {
    s32 done;
    u16 t;

    t = F(u16, 4);
    F(u16, 4) = t + 1;
    if ((s16)t >= 0x1E) {
        F(u16, 4) = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        background_objects[0].x_pos.u.hi = 0xE00;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 0;
        F(u8, 1)++;
    }
}

#undef F
