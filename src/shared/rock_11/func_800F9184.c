// rolefeed (3.1 T4): func_800F9184 of src/rock_11/E9860.c
#include "common.h"
#include "mmx6/rock_11.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F9EB4(u8* arg0, u8 arg1, s16 arg2);

void func_800F9184(u8* arg0) {
    s8 state = arg0[0x45];

    if (state == 1) {
        play_sound(2, 0x25, arg0);
        play_sound(2, 0x47, arg0);
        func_800F9EB4(arg0, 0x30, 0);
        func_800F9EB4(arg0, 0x30, 0x400);
        func_800F9EB4(arg0, 0x30, 0x800);
        func_800F9EB4(arg0, 0x30, 0xC00);
        func_800F9EB4(arg0, 0x30, 0x200);
        func_800F9EB4(arg0, 0x30, 0x600);
        func_800F9EB4(arg0, 0x30, 0xA00);
        func_800F9EB4(arg0, 0x30, 0xE00);
    } else if (state == 2) {
        if (--((s8*)arg0)[0x8C] == 0) {
            *(s16*)(arg0 + 0x84) = 1;
            arg0[5] = 4;
            arg0[6] = 0;
        } else {
            arg0[6]--;
        }
    }
}
