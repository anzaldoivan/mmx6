#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
s32 random_byte();
void func_800F1FBC();
void func_800F3EC4(void* arg0, u8 arg1, s16 arg2, s16 arg3);
void func_800F4664(s16 arg0, s16 arg1);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;

void func_800EE990(u8* self) {
    s32 x;
    s32 y;

    if (D_80097420 & 3) {
        x = (s16)(random_byte() % 150);
        y = (s16)(random_byte() % 120);
        if (random_byte() & 1) {
            x = (s16)-x;
        }
        if (random_byte() & 1) {
            y = (s16)-y;
        }
        func_800F4664(x + (background_objects[0].x_pos.u.hi + 0x96),
                      y + (background_objects[0].y_pos.u.hi + 0x78));
    }
    if (D_80097420 & 7) {
        x = (s16)(random_byte() % 150);
        if (random_byte() & 1) {
            x = (s16)-x;
        }
        func_800F3EC4(self, 0x60, x + (background_objects[0].x_pos.u.hi + 0x96),
                      background_objects[0].y_pos.u.hi - 0xA);
    }
    if (!(D_80097420 & 0x1F)) {
        func_80012D9C(3);
    }
    if (((s8*)&D_80097420)[5] == 0) {
        func_800F1FBC();
        ((s8*)self)[7] = -1;
        *(s16*)(self + 0x7C) = 0x3C;
        self[6]++;
    }
}
