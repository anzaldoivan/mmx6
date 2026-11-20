// rolefeed (3.1 T4): func_800F64BC of src/rock_07/E9860.c
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

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
void func_800F4144(void* arg0);
extern s16 D_800F9868;

void func_800F64BC(void* arg0) {
    if (D_800F9868 == 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x61, arg0);
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        func_800F4144(arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0x24);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
