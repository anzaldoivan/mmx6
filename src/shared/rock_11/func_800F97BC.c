// rolefeed (3.1 T4): func_800F97BC of src/rock_11/E9860.c
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

M2C_UNK set_animation(void*, M2C_UNK);
void func_800FA150(void*, s32);
extern s16 D_800970AA;
extern u8 D_800E9B8C[];

void func_800F97BC(void* arg0) {
    s8 buf[4];

    __builtin_memcpy(buf, D_800E9B8C, 4);
    set_animation(arg0, 8);
    func_800FA150(arg0, 1);
    if (*(s16*)((u8*)arg0 + 0xA) < D_800970AA) {
        *((u8*)arg0 + 0x15) = 0x40;
        *(s32*)((u8*)arg0 + 0x20) = 0xFFFB0000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    } else {
        *((u8*)arg0 + 0x15) = 0;
        *(s32*)((u8*)arg0 + 0x20) = 0x50000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    }
    *(s32*)((u8*)arg0 + 0x24) = 0;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *((u8*)arg0 + 6) = 1;
}
