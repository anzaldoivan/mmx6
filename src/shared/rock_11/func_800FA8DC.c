// rolefeed (3.1 T4): func_800FA8DC of src/rock_11/E9860.c
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
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800FD470[];
extern u8 D_800FD474[];
extern u8 D_800FD47C[];
extern u8 D_800FD480[];

void func_800FA8DC(void* self) {
    play_sound(2, 0x46, self);
    if (M2C_FIELD(self, s16*, 0xE) > D_800970AE) {
        set_animation(self, 0xA);
        M2C_FIELD(self, void**, 0x50) = D_800FD470;
        M2C_FIELD(self, void**, 0x68) = D_800FD47C;
        M2C_FIELD(self, s32*, 0x24) = 0x18000;
        M2C_FIELD(self, u8*, 0x7) = 0;
        M2C_FIELD(self, u8*, 0x6)++;
    } else {
        set_animation(self, 0xB);
        M2C_FIELD(self, void**, 0x50) = D_800FD474;
        M2C_FIELD(self, void**, 0x68) = D_800FD480;
        M2C_FIELD(self, s32*, 0x24) = 0xFFFE8000;
        M2C_FIELD(self, u8*, 0x7) = 1;
        M2C_FIELD(self, u8*, 0x6)++;
    }
    M2C_FIELD(self, s32*, 0x20) = 0;
    if ((M2C_FIELD(self, u8*, 0x2) & 0xF) == 1) {
        M2C_FIELD(self, s32*, 0x24) *= 2;
    }
}
