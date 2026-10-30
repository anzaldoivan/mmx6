#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 random_byte();
void func_800F6E48(struct X4_MainObj*);

void func_800F4D00(struct X4_MainObj* arg0) {
    s32 v;
    s32 g;

    set_animation(arg0, 0xD);
    func_800F6E48(arg0);
    v = (u8)((u32)random_byte() % 15) + 0xA;
    g = 0x460000 / ((v * v) >> 1);
    arg0->gravity = g;
    arg0->x_speed = 0;
    arg0->x_accel = 0;
    arg0->y_speed = g * v;
    func_8002D230(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (41/44)
        register s32 t asm("$2") = (u8)arg0->unk6 + 1;
        arg0->unk6 = t;
    }
}
