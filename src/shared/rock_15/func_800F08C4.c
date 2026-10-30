#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
s32 func_8002D30C();
void func_8004A768();
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F6F10[];

void func_800F08C4(void* arg0) {
    s16 x;
    s16 y;
    s32 r;

    x = background_objects[0].x_pos.i.hi;
    y = background_objects[0].y_pos.i.hi;
    {
        s32 t = func_8002D30C();
        r = t - (t / 4) * 4;
    }
    M2C_FIELD(arg0, s32*, 0x94) = r;
    x += 0xA0;
    y += 0x3C;
    switch (r) {
    case 0:
        break;
    case 1:
        x += 0x50;
        break;
    case 2:
        y += 0x3C;
        break;
    case 3:
        x += 0x50;
        y += 0x3C;
        break;
    }
    x += func_8002D30C() % 80;
    y += func_8002D30C() % 60;
    func_8004A768(D_800F6F10[(random_byte() & 3) * 4], (s16)(x - 0x20),
                  (s16)(y - 0x20), (s16)(x + 0x20), (s16)(y + 0x20), 4);
}
