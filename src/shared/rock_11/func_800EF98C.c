#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
void func_800F4328(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800E98A4[];

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF98C(void* arg0) {
    s16 t[8][2];
    s32 i;

    __builtin_memcpy(t, D_800E98A4, 32);
    if (!(F(u16, 0x7C) & 7)) {
        i = F(s16, 0x7C) >> 3;
        func_800F4328(arg0, (i + 0x31) & 0xFF,
                      background_objects[0].x_pos.i.hi + t[i][0],
                      background_objects[0].y_pos.i.hi + t[i][1]);
    }
    if (++F(s16, 0x7C) == 0x39) {
        F(s8, 0x8C) = random_byte() & 3;
        F(u8, 0x8D) = 0;
        F(s16, 0x7C) = 0x5A;
        F(u8, 0x6)++;
    }
}
