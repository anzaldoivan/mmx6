// rolefeed (3.1 T4): func_800F23B0 of src/rock_05/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);        /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK animate_object();                    /* extern */
void move_object();                          /* extern */
extern u16 D_800F447E;
#define D_800F447E_S (*(s16*)&D_800F447E)

void func_800F23B0(void* arg0) {
    s16 y;

    ((void (*)(void*))move_object)(arg0);
    ((void (*)(void*))animate_object)(arg0);
    y = M2C_FIELD(arg0, s16*, 0xA);
    if ((D_800F447E_S + 0x11F0) < y) {
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFF80000;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        play_sound(2, 2, arg0);
        start_pad_vibration(4);
        return;
    }
    if (y < (D_800F447E_S + 0xFA0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x80000;
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        play_sound(2, 2, arg0);
        start_pad_vibration(4);
    }
}
