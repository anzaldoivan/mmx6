#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002D2D4();
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FB26C[];
extern u8 D_800FC9D8[];
extern u8 D_800FC9E0[];
extern s8 D_800FD514;

#define TB (D_800FB26C + 0xE44)
#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EEBBC(void* self) {
    s32 r;

    F(u8, 0x7) = 0;
    if ((s16)(F(s16, 0x7C) % 12) == 0) {
        func_80027BA0(1, background_objects[0].x_pos.i.hi + 0xC0,
                      background_objects[0].y_pos.i.hi - 0x10,
                      &D_800FC9E0[F(s16, 0x7E) * 8]);
        background_objects[1].unk4C = 1;
        if (++F(s16, 0x7E) == 4) {
            F(s16, 0x7E) = 0;
        }
    }
    if (--F(s16, 0x7C) == 0) {
        func_80027BA0(1, background_objects[0].x_pos.i.hi + 0xC0,
                      background_objects[0].y_pos.i.hi - 0x10, D_800FC9D8);
        background_objects[1].unk4C = 1;
        F(s8, 0x87) = D_800FD514;
        r = func_8002D2D4() & 0xF;
        F(s8, 0x85) = r;
        F(s8, 0x86) = 0;
        F(u8, 0x5) = TB[F(s8, 0x87) * 128 + r * 8];
        F(s8, 0x6) = 0;
    }
}

#undef F
#undef TB
