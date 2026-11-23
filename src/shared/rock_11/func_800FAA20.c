// rolefeed (3.1 T4): func_800FAA20 of src/rock_11/E9860.c
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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_80097222;
extern s32 D_800FD484;
extern s32 D_800FD488;

void func_800FAA20(void* arg0) {
    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FD484;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FD488;
    M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x120;
    if (!(M2C_FIELD(arg0, u8*, 2) & 0xF)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
    }
    M2C_FIELD(arg0, s16*, 0x88) = 0xC;
    M2C_FIELD(arg0, s16*, 0x8A) = 4;
    M2C_FIELD(arg0, u8*, 6) += 1;
}
