#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
s32 func_8002D30C();
M2C_UNK func_8004A0C0(M2C_UNK, s16, s16, s32);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern u8 D_800F6F20[];

void func_800F0A78(void* arg0) {
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
    if (M2C_FIELD(arg0, s8*, 4) == 1) {
        x += 0xA0;
        y += 0xDC;
        switch (r) {
        case 0:
            break;
        case 1:
            x += 0x50;
            break;
        case 2:
            y -= 0x3C;
            break;
        case 3:
            x += 0x50;
            y -= 0x3C;
            break;
        }
        x += func_8002D30C() % 80;
        y -= func_8002D30C() % 60;
    } else {
        switch (r) {
        case 0:
            break;
        case 1:
            x += 0xA0;
            break;
        case 2:
            y += 0x78;
            break;
        case 3:
            x += 0xA0;
            y += 0x78;
            break;
        }
        x += func_8002D30C() % 160;
        y += func_8002D30C() % 120;
    }
    func_8004A0C0(0, x, y, 0xFF);
    if (!(D_80097420 & 3)) {
        play_sound(0, D_800F6F20[(random_byte() & 3) * 4], 0);
    }
}
