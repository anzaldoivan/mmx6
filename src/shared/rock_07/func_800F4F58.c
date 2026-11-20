// rolefeed (3.1 T4): func_800F4F58 of src/rock_07/E9860.c
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

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6E48(struct X4_MainObj*);

void func_800F4F58(struct X4_MainObj* arg0) {
    play_sound(2, 0x5B, arg0);
    set_animation(arg0, 3);
    func_800F6E48(arg0);
    *((u8*)arg0 + 6) = *((u8*)arg0 + 6) + 1;
}
