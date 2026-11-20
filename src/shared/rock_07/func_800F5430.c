// rolefeed (3.1 T4): func_800F5430 of src/rock_07/E9860.c
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
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
void move_object();
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F5430(void* arg0) {
    if (F(u8, 0x70) & 8) {
        play_sound(2, 0x5E, arg0);
        start_pad_vibration(5);
        func_8002943C(0x32, 3, 2);
        set_animation(arg0, 0xC);
        func_800F6880(arg0, 0x10, F(s16, 0xA), F(s16, 0xE) + 0x20);
        func_800F6880(arg0, 0x10, F(s16, 0xA), F(s16, 0xE) + 0x20);
        func_800F6880(arg0, 0x11, F(s16, 0xA), F(s16, 0xE) + 0x20);
        func_800F6880(arg0, 0x12, F(s16, 0xA), F(s16, 0xE) + 0x20);
        F(u8, 6)++;
        return;
    }
    move_object(arg0);
}
