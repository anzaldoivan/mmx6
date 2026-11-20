// rolefeed (3.1 T4): func_800F2884 of src/rock_07/E9860.c
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
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
void move_object();
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
void func_800F6E48(struct X4_MainObj*);

void func_800F2884(void* arg0) {
    s16 n;

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
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        func_800F6880(arg0, 0x10, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        func_800F6880(arg0, 0x11, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        func_800F6880(arg0, 0x12, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        M2C_FIELD(arg0, u8*, 6) += 2;
        return;
    }
    n = --M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0) {
        M2C_FIELD(arg0, u8*, 3) = 1;
        func_800F6E48((struct X4_MainObj*)arg0);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x50000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x50000;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    move_object(arg0);
}
