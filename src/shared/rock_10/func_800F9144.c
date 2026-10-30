#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);
extern struct X4_BackgroundObj background_objects[3];

void func_800F9144(struct X4_AnimatedObj* arg0) {
    s8 s = M2C_FIELD(arg0, s8*, 0x45);

    if (s == 1) {
        play_sound(2, 0x59, arg0);
        set_animation(arg0, 0xC);
        func_800F9E04(arg0);
        arg0->unk15 = 0x40;
        arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0xA0;
        arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x50;
        arg0->unk6++;
    } else if (s == 2) {
        play_sound(2, 0x59, arg0);
    } else if (s == 3) {
        play_sound(2, 0x51, arg0);
    }
}
