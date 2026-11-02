#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);

#define PAL_BUF (*(u8**)0x1F800024)

void func_8003CF24(s32 arg0, s32 arg1, s32 arg2) {
    load_palette(arg1, (s32*)(PAL_BUF + (arg0 << 5)), arg2);
}
#undef PAL_BUF

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);

#define PAL_BUF (*(u8**)0x1F800024)
#define PAL_BUF_B ((u8*)((struct X4_PlayerObj*)0x1F800000)->y_vel.val)

void func_8003CF54(struct X4_PlayerObj* self, s32 arg1) {
    if (self->unk2 == 0) {
        load_palette(0, (s32*)(PAL_BUF + (arg1 << 5)), 1);
        load_palette(0x13, (s32*)(PAL_BUF_B + ((arg1 + 1) << 5)), 1);
    } else {
        load_palette(0, (s32*)(PAL_BUF + (arg1 << 5)), 1);
    }
}
#undef PAL_BUF
#undef PAL_BUF_B

#include "common.h"
#define M2C_UNK s32

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */

M2C_UNK func_8003CFE0(void* arg0, M2C_UNK arg1) {
    arg1 &= 0xFF;
    if (((s8*)arg0)[0x8D] <= 0) {
        play_sound(3, arg1, arg0);
    }
}
