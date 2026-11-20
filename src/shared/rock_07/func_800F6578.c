// rolefeed (3.1 T4): func_800F6578 of src/rock_07/E9860.c
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

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F90C8;
extern s32 D_800F90CC;

void func_800F6578(u8* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0x1A);
    *(s32**)(arg0 + 0x50) = &D_800F90C8;
    *(s32**)(arg0 + 0x54) = &D_800F90CC;
    arg0[6]++;
}
