#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
extern struct X4_BackgroundObj background_objects[3];

void func_800F5378(struct X4_AnimatedObj* arg0) {
    s32 r;
    s32 n;
    s32 m;
    s32 x;
    // !FAKE: depin: dropping it breaks the match (114/138)
    register s32 y asm("$3");

    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        if (M2C_FIELD(arg0, s16*, 0x7E) == 0) {
            play_sound(2, 0x59, arg0);
        } else {
            play_sound(2, 0x5A, arg0);
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        arg0->unk16 = 4;
        r = random_byte() & 3;
        switch (r) {
        case 0:
            arg0->unk15 = 0;
            arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x120;
            arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x20;
            break;
        case 1:
            arg0->unk15 = 0x40;
            arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x20;
            arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x20;
            break;
        case 2:
            arg0->unk15 = 0x40;
            arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x20;
            arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x90;
            break;
        case 3:
            arg0->unk15 = 0;
            arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0x120;
            arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x90;
            break;
        }
        m = (u8)((u32)random_byte() % 3);
        n = (u8)(r + 1);
        n = (n + m) & 3;
        switch (n) {
        case 0:
            x = 0x120;
            y = 0x20;
            goto store;
        case 1:
            M2C_FIELD(arg0, s16*, 0x84) = 0x20;
            M2C_FIELD(arg0, s16*, 0x86) = 0x20;
            break;
        case 2:
            x = 0x20;
            y = 0x90;
            goto store;
        case 3:
            x = 0x120;
            y = 0x90;
        store:
            M2C_FIELD(arg0, s16*, 0x84) = x;
            M2C_FIELD(arg0, s16*, 0x86) = y;
            break;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        arg0->unk6++;
    }
}
