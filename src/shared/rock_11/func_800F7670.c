// rolefeed (3.1 T4): func_800F7670 of src/rock_11/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F7BE4(void* arg0);

void func_800F7670(void* arg0) {
    s32 kind;
    u8 sub;

    sub = M2C_FIELD(arg0, u8*, 0x2);
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    kind = M2C_FIELD(arg0, s8*, 0x2) & 0xF0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    if (kind == 0) {
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        M2C_FIELD(arg0, s16*, 0x54) = 0x1E;
        M2C_FIELD(arg0, u8*, 0x0) |= 0x10;
    } else if (kind == 0x10) {
        switch (sub & 0xF) {
        case 0:
            ((void (*)(void*, s32))set_animation)(arg0, 0x10);
            break;
        case 1:
            ((void (*)(void*, s32))set_animation)(arg0, 0x11);
            break;
        }
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        M2C_FIELD(arg0, u8*, 0x5) = 1;
    } else if (kind == 0x20) {
        M2C_FIELD(arg0, u8*, 0x16) = 7;
        if ((sub & 0xF) == 1) {
            ((void (*)(void*, s32))set_animation)(arg0, 0x1B);
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x80, 0x80);
        } else {
            func_800F7BE4(arg0);
        }
        M2C_FIELD(arg0, u8*, 0x4)++;
    } else if (kind == 0x30) {
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, s16*, 0x54) = 0x1E;
        M2C_FIELD(arg0, u8*, 0x0) |= 0x10;
    }
}
