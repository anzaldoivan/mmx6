#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800EBBF8(struct X4_MainObj* arg0) {
    background_objects[1].y_pos.val += 0xFFFF3334;
    if (background_objects[1].y_pos.i.hi < 0x321) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x44, arg0);
        ((void (*)(s32))func_80012D9C)(5);
        background_objects[1].y_pos.i.hi = 0x320;
        arg0->unk7C = 0x3C;
        arg0->unk6++;
    }
}
