#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_1C (*(u8**)0x1F80001C)

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
extern M2C_UNK g_Player;
extern s32 D_8007798C;
extern s32 D_801F3ABC;

void func_801F2A38(void* arg0) {
    u8* p;
    u8* player;
    s32 off;

    M2C_FIELD(arg0, s8*, 3) = 1;
    p = SCRATCH_1C;
    off = M2C_FIELD(p, s32*, 0x68);
    M2C_FIELD(arg0, s32*, 0x30) = (s32)&D_8007798C;
    M2C_FIELD(arg0, s16*, 0x40) = 0;
    M2C_FIELD(arg0, s16*, 0x42) = 0x7802;
    M2C_FIELD(arg0, s8*, 0x16) = 0x11;
    M2C_FIELD(arg0, s32*, 0x24) = 0x100000;
    M2C_FIELD(arg0, s8*, 0x64) = 1;
    M2C_FIELD(arg0, u8**, 0x3C) = p + off;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        set_animation(arg0, 0xB);
        M2C_FIELD(arg0, s32*, 0x50) = (s32)&D_801F3ABC;
    } else {
        set_animation(arg0, 0xC);
    }
    player = (u8*)&g_Player;
    M2C_FIELD(arg0, u8*, 4)++;
    player[0x99]++;
    player[0x98]++;
}
#undef set_animation
#undef SCRATCH_1C
