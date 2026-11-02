#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_80074BFC;
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern u8 D_800CCF38;
extern s32 D_800F7D60;
extern s32 D_800F7D64;
extern s32 D_800F7D68;

// 0x800F3BE4 init_yammark_projectile: Yammark projectile setup; difficulty branch, speed.
// basis: community tweaks-index.tsv:162
// callers: none known
void init_yammark_projectile(void* arg0) {
    void* parent;
    s16 angle;
    u16 x;
    u16 y;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x14) = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(arg0, void**, 0x50) = &D_800F7D64;
    M2C_FIELD(arg0, u8*, 0x16) = 3;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F7D60;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F7D68;
    M2C_FIELD(arg0, void**, 0x58) = &D_80074BFC;
    ((void (*)(void*, s32))set_animation)(arg0, 0x11);
    M2C_FIELD(arg0, u16*, 0xA) = x =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = y =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xE);
    if (D_800CCF38 != 2) {
        if (D_800970AA > (s16)x) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = -0x30000;
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) =
            (M2C_FIELD(arg0, s32*, 0x20) * 0x7D) / 100;
    } else {
        angle =
            ratan2(g_Player.y_pos.i.hi - (s16)y, g_Player.x_pos.i.hi - (s16)x);
        M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) * 0x30;
        M2C_FIELD(arg0, s32*, 0x24) = -rsin(angle) * 0x30;
        if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, u8*, 0x60) = 2;
    play_sound(2, 0x32, arg0);
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
}
