// rolefeed (3.1 T4): func_800F63CC of src/rock_11/E9860.c
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

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void move_object();
s32 func_800FA4F8(void* arg0, s16 arg1, s32 arg2);
extern u16 D_80097222;

void func_800F63CC(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x6)++;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
    } else if (M2C_FIELD(arg0, u8*, 0x70) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
    }
    move_object(arg0);
    switch (M2C_FIELD(arg0, s8*, 0x7)) {
    case 0:
        func_800FA4F8((u8*)arg0 + 0xC, D_80097222 + 0x70, 0x10000);
        break;
    case 1:
        func_800FA4F8((u8*)arg0 + 0xC, D_80097222 + 0x90, 0x10000);
        break;
    case 2:
        func_800FA4F8((u8*)arg0 + 0xC, D_80097222 + 0xB0, 0x10000);
        break;
    }
}
