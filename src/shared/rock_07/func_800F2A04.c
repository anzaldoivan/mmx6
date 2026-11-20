// rolefeed (3.1 T4): func_800F2A04 of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
void move_object();
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern s16 D_800970AA;

void func_800F2A04(void* arg0) {
    s16 n;
    s32 v;

    n = --M2C_FIELD(arg0, u16*, 0x7E);
    if (n == 0) {
        play_sound(2, 0x5E, arg0);
        start_pad_vibration(5);
        set_animation_frame(arg0, 0x21, 4);
        M2C_FIELD(arg0, u8*, 0x60) = 4;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x20;
        M2C_FIELD(arg0, s16*, 0x86) = M2C_FIELD(arg0, s16*, 0xE) - 0x48;
        func_800F6880(arg0, 0x10, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x20);
        func_800F6880(arg0, 0x10, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x20);
        func_800F6880(arg0, 0x11, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x20);
        func_800F6880(arg0, 0x12, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x20);
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    if (n == 0x1B || n == 0x57) {
        play_sound(2, 0x5F, arg0);
    }
    {
        ((void (*)(void*))move_object)(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            if (D_800970AA < M2C_FIELD(arg0, s16*, 0xA)) {
                v = M2C_FIELD(arg0, u8*, 0x70) & 2;
            } else {
                M2C_FIELD(arg0, s16*, 0x7C) = 4;
                M2C_FIELD(arg0, u8*, 6) -= 1;
                return;
            }
        } else if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            v = M2C_FIELD(arg0, u8*, 0x70) & 1;
        } else {
            M2C_FIELD(arg0, s16*, 0x7C) = 4;
            M2C_FIELD(arg0, u8*, 6) -= 1;
            return;
        }
        if (v != 0) {
            M2C_FIELD(arg0, s16*, 0x7C) = 4;
            M2C_FIELD(arg0, u8*, 6) -= 1;
            return;
        }
        if (!(D_80097420.frame_counter & 3)) {
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                func_800F6880(arg0, 0x15, M2C_FIELD(arg0, s16*, 0xA) - 8,
                              M2C_FIELD(arg0, s16*, 0xE) + 8);
            } else {
                func_800F6880(arg0, 0x14, M2C_FIELD(arg0, s16*, 0xA) + 8,
                              M2C_FIELD(arg0, s16*, 0xE) + 8);
            }
        }
    }
}
