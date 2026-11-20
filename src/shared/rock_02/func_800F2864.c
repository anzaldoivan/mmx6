// rolefeed (3.1 T4): func_800F2864 of src/rock_02/E9860.c
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
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern s16 D_80097222;
extern s32 D_800FB2E8;

void func_800F2864(void* arg0) {
    u8* sp;
    u8 t;

    sp = SPAD4C;
    t = sp[0x8B];
    if (t != 0) {
        sp[0x8B] = t - 1;
        if (!(SPAD4C[0x8B] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) | 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        }
    }
    if (D_80097222 + 0x20 < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, void**, 0x68) = &D_800FB2E8;
    }
    ((void (*)(void*))animate_object)(arg0);
    ((void (*)(void*))apply_object_motion)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        start_pad_vibration(3);
        play_sound(2, 0x1B, arg0);
        play_sound(2, 0x21, arg0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        func_80029478(0x5A, 2, 2);
        SPAD4C[0x8B] = 0x78;
    }
}
