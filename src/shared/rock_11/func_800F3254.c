#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FB26C[];
extern s8 D_800FD514;
extern s16 D_800FD52A;

#define TB (D_800FB26C + 0xE44)
#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F3254(void* self) {
    s32 r;

    background_objects[0].unk24 = 0x1080;
    background_objects[0].unk28 = D_800FD52A;
    F(s8, 0x6) = 0;
    F(s8, 0x87) = D_800FD514;
    r = random_byte() & 0xF;
    F(s8, 0x85) = r;
    F(s8, 0x86) = 0;
    F(u8, 0x5) = TB[F(s8, 0x87) * 128 + r * 8];
}

#undef F
#undef TB
