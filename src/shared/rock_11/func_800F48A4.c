#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FCBA0;
extern s16 D_800FD516;
extern s16 D_800FD518;

void func_800F48A4(u8* arg0) {
    arg0[0x14] = 0;
    arg0[3] = 0;
    *(void**)(arg0 + 0x50) = &D_800FCBA0;
    *(s16*)(arg0 + 0xA) = background_objects[0].x_pos.u.hi + D_800FD516;
    *(s16*)(arg0 + 0xE) = background_objects[0].y_pos.u.hi + D_800FD518;
    if (--*(s16*)(arg0 + 0x88) == 0) {
        func_80016C48(2, 0x39, arg0);
        arg0[4]++;
    }
}
