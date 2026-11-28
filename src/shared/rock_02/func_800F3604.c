// rolefeed (3.1 T4): func_800F3604 of src/rock_02/E9860.c
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
extern u8 D_800FB810[];
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
void move_object();
extern u16 D_8009721A;

void func_800F3604(void* arg0) {
    s32 t;
    s32 v;

    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (s16)D_8009721A + 0x40) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x40;
        if (SPAD4C[0x8A] != 0x11) {
            M2C_FIELD(arg0, u8*, 5) = 0xE;
            M2C_FIELD(arg0, u8*, 6) = 0;
            SPAD4C[0x85]++;
            return;
        }
        if (--M2C_FIELD(arg0, s16*, 0x7E) != 0) {
            set_animation(arg0, 7);
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6) = 1;
            return;
        }
        t = SPAD4C[0x85] + 1;
        SPAD4C[0x85] = t;
        v = D_800FB810[(t & 3) + SPAD4C[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}
