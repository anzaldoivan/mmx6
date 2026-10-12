#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj D_800971F8[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EBB44(void* self) {
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
        D_800971F8[0].x_pos.u.hi = 0x600;
        D_800971F8[0].unk4C = 1;
        D_800971F8[0].unk3 = 0;
        F(u8, 1)++;
    }
}

#undef F
