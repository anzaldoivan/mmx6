// rolefeed (3.1 T4): func_800F6524 of src/rock_07/E9860.c
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

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6E78(void*);

void func_800F6524(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((void (*)())func_800F6E78)();
        ((void (*)(void*, s32))set_animation)(arg0, 0x19);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
