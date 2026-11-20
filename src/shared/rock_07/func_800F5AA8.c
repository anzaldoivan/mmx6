// rolefeed (3.1 T4): func_800F5AA8 of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
void func_800F67D0(void*, s32);

void func_800F5AA8(u8* arg0) {
    s8 state = *(s8*)(arg0 + 0x45);

    if (state == 1) {
        if (D_800CCF38 >= 2 && (random_byte() & 1)) {
            play_sound(2, 0x29, arg0);
            func_800F67D0(arg0, 3);
        } else if (D_800970A2 == 0) {
            play_sound(2, 0x28, arg0);
            func_800F67D0(arg0, 2);
        } else {
            play_sound(2, 0x27, arg0);
            func_800F67D0(arg0, 1);
        }
        arg0[7] = 1;
        arg0[6]++;
    } else if (state == 2) {
        play_sound(2, 0x60, arg0);
    }
}
