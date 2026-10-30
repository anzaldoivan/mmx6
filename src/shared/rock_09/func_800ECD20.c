#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 set_animation(void*, s32);
s32 func_8002A47C(s32);
extern s32 D_80075B9C;
extern u32* D_80095098;
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_800F6084;
extern s32 D_800F608C;
extern s32 D_800F6090;

void func_800ECD20(s8* self) {
    struct X4_PlayerObj* pl = &g_Player;
    s32 a;
    s32 b;
    s32 k;

    M2C_FIELD(self, s8*, 0x5) = 2;
    M2C_FIELD(self, s8*, 0x0) = 0x41;
    M2C_FIELD(self, s8*, 0x4)++;
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(pl, u8*, 0x14);
    M2C_FIELD(self, u16*, 0x40) = D_80095098[func_8002A47C(0x83)] >> 7;
    M2C_FIELD(self, u8**, 0x3C) = (u8*)SPAD20 + SPAD20[func_8002A47C(0x83)];
    a = func_8002A47C(0x83);
    b = func_8002A47C(0x83);
    M2C_FIELD(self, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    k = 7;
    do {
        M2C_FIELD(self, void**, 0x68) = &D_800F6090;
        M2C_FIELD(self, u8*, 0x16) = k;
        M2C_FIELD(self, void**, 0x54) = &D_800F608C;
        M2C_FIELD(self, void**, 0x58) = &D_80075B9C;
        M2C_FIELD(self, void**, 0x30) = &D_800F6084;
        M2C_FIELD(self, s8*, 0x61) = 0;
        M2C_FIELD(self, u8*, 0x15) = 0;
        M2C_FIELD(self, s8*, 0x65) = 0;
        M2C_FIELD(self, s8*, 0x75) = 1;
        M2C_FIELD(self, s8*, 0x76) = 0;
        M2C_FIELD(self, s8*, 0x60) = 0xA;
        M2C_FIELD(self, s8*, 0xA2) = 1;
        M2C_FIELD(self, s8*, 0x84) = 0;
        M2C_FIELD(self, s16*, 0x7C) = M2C_FIELD(self, s16*, 0xA);
        M2C_FIELD(self, s16*, 0x7E) = M2C_FIELD(self, s16*, 0xE);
        if (M2C_FIELD(self, s8*, 0x2) != 0) {
            set_animation(self, 0);
            M2C_FIELD(self, s8*, 0x6) = 1;
            M2C_FIELD(self, s32*, 0x20) = 0;
            M2C_FIELD(self, s32*, 0x24) = 0x10000;
        } else {
            set_animation(self, 1);
            M2C_FIELD(self, s8*, 0x6) = 2;
            M2C_FIELD(self, s32*, 0x20) = 0x10000;
            M2C_FIELD(self, s32*, 0x24) = 0;
            if (pl->x_pos.val < M2C_FIELD(self, s32*, 0x8)) {
                M2C_FIELD(self, s32*, 0x20) = 0xFFFF0000;
            }
        }
    } while (0);
}
#undef g_Player
