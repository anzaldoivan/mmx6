#include "common.h"
#include "mmx6/x4.h"

void func_800F440C(s8 arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800E987C[];

void func_800F2F10(u8* self) {
    u16 pos[4];

    __builtin_memcpy(pos, D_800E987C, 8);
    self[7] = 0;
    switch (--*(s16*)(self + 0x7C)) {
    case 1:
        func_800F440C(0xB, 0x10, background_objects[0].x_pos.u.hi + pos[0],
                      background_objects[0].y_pos.u.hi + pos[1]);
        break;
    case 0:
        func_800F440C(0xB, 0x10, background_objects[0].x_pos.u.hi + pos[2],
                      background_objects[0].y_pos.u.hi + pos[3]);
        *(s16*)(self + 0x7C) = 0x28;
        self[6]++;
        break;
    }
}
