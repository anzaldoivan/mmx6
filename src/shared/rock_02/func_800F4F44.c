// rolefeed (3.1 T4): func_800F4F44 of src/rock_02/E9860.c
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
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK clear_object_slot();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030ECC();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern void (*D_800FBAA4[])(void*);

void func_800F4F44(void* arg0) {
    void* p;
    u8* g;
    s8 t;

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    t = M2C_FIELD(p, s8*, 4);
    if (t == 2) {
        M2C_FIELD(arg0, s8*, 4) = t;
        play_sound(2, 0x14, arg0);
        return;
    }
    if (M2C_FIELD(p, s8*, 5) == 8 && M2C_FIELD(p, s8*, 6) > 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 6 || M2C_FIELD(arg0, s8*, 2) == 9 ||
            M2C_FIELD(arg0, s8*, 2) == 10) {
            if (M2C_FIELD(arg0, s8*, 2) == 9) {
                M2C_FIELD(p, u8*, 0x8A) &= 0xF0;
            } else if (M2C_FIELD(arg0, s8*, 2) == 10) {
                M2C_FIELD(p, u8*, 0x8A) &= 0xF;
            }
            M2C_FIELD(arg0, s8*, 4) = 2;
            play_sound(2, 0x14, arg0);
            return;
        }
    }
    D_800FBAA4[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (M2C_FIELD(arg0, s8*, 5) == 4 || M2C_FIELD(arg0, s8*, 5) == 5) {
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    {
        ((void (*)(void*))func_80030ECC)(arg0);
        if (M2C_FIELD(p, s8*, 2) == 0) {
            g = (u8*)&g_Player;
            if (M2C_FIELD(g, s8*, 0x5C) == -0x80) {
                M2C_FIELD(g, s8*, 0x5C) = 1;
            }
            if ((M2C_FIELD(g, s8*, 0x5C) & 0x7F) < 2) {
                M2C_FIELD(g, s8*, 0x5C) = 1;
                func_8003D308(0x14, M2C_FIELD(g, u8*, 0x15));
                play_sound(2, 0x14, arg0);
                clear_object_slot(arg0);
                return;
            }
        }
        if (is_off_screen(arg0, 0x60, 0x40) == 0) {
            if (M2C_FIELD(arg0, s8*, 2) == 9 || M2C_FIELD(arg0, s8*, 2) == 10) {
                return;
            }
            func_8002CCB0(arg0, 0x40, 0x40);
        } else {
            if (M2C_FIELD(arg0, s8*, 2) == 1 || M2C_FIELD(arg0, s8*, 2) == 6 ||
                M2C_FIELD(arg0, s8*, 2) == 7) {
                play_sound(2, 0x14, arg0);
            }
            if (M2C_FIELD(arg0, s8*, 2) != 9 && M2C_FIELD(arg0, s8*, 2) != 10) {
                M2C_FIELD(arg0, s8*, 4) = 2;
            }
        }
    }
}
