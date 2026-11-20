// rolefeed (3.1 T4): func_800F4C44 of src/rock_02/E9860.c
#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK silence_sound(M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_8007523C;
extern struct X4_PlayerObj g_Player;
extern void (*D_800FB850[])(void*);

#define SPAD (*(u8**)0x1F80004C)

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
s32 random_byte();
s32 check_enemy_hits(void*);
extern void (*D_800FBA98[])(void*);

void func_800F4C44(void* arg0) {
    void* child;
    s32 i;
    s32 r;

    if (check_enemy_hits(arg0) < 0 && M2C_FIELD(arg0, s8*, 6) != 4) {
        r = random_byte() & 0x2D;
        if (D_800CCF38 >= 2) {
            for (i = 0; i < 6; i++) {
                child = func_8002C458();
                if (child != 0) {
                    s16 ang;
                    s32 t;
                    s32 v;
                    M2C_FIELD(child, u8*, 0) = 0x41;
                    M2C_FIELD(child, u8*, 1) = 0x15;
                    M2C_FIELD(child, u8*, 2) = 8;
                    M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                    M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                    M2C_FIELD(child, u16*, 0x42) = 0x7948;
                    M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(child, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(child, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
                    ang = ((i * 60 + r) << 12) / 360;
                    t = rcos(ang);
                    v = t * 16;
                    M2C_FIELD(child, s32*, 0x20) = t * 32 + v;
                    t = rsin(ang);
                    v = t * 16;
                    t = t * 32 + v;
                    M2C_FIELD(child, s32*, 0x24) = t;
                    M2C_FIELD(child, u8*, 7) = (i + 1) * 0x28;
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                child = func_8002C458();
                if (child != 0) {
                    s16 ang;
                    s32 t;
                    s32 v;
                    M2C_FIELD(child, u8*, 0) = 0x41;
                    M2C_FIELD(child, u8*, 1) = 0x15;
                    M2C_FIELD(child, u8*, 2) = 8;
                    M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                    M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                    M2C_FIELD(child, u16*, 0x42) = 0x7948;
                    M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(child, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(child, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
                    ang = ((i * 90 + r) << 12) / 360;
                    t = rcos(ang);
                    v = t * 16;
                    M2C_FIELD(child, s32*, 0x20) = t * 32 + v;
                    t = rsin(ang);
                    v = t * 16;
                    t = t * 32 + v;
                    M2C_FIELD(child, s32*, 0x24) = t;
                    M2C_FIELD(child, u8*, 7) = (i + 1) * 0x28;
                }
            }
        }
        M2C_FIELD(arg0, u8*, 6) = 2;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s16*, 0x90) = 0;
        M2C_FIELD(arg0, u8*, 0x47) = 0xE;
        M2C_FIELD(arg0, u8*, 0) |= 0x10;
        play_sound(2, 0x14, arg0);
        play_sound(2, 0x7C, arg0);
    }
    D_800FBA98[M2C_FIELD(arg0, s8*, 6)](arg0);
}
