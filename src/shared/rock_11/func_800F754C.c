// rolefeed (3.1 T4): func_800F754C of src/rock_11/E9860.c
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
void move_object();
s32 func_800FA630(void*, s16, s16);

#define F_S8(o) (*(s8*)((u8*)self + (o)))
#define F_U8(o) (*(u8*)((u8*)self + (o)))
#define F_S16(o) (*(s16*)((u8*)self + (o)))
#define F_S32(o) (*(s32*)((u8*)self + (o)))

void func_800F754C(void* self) {
    if (F_S8(0x7) == 0) {
        if (func_800FA630(self, F_S16(0xA), F_S16(0xE) - 0x10) != 0 ||
            (F_U8(0x70) & 4)) {
            set_animation(self, 0xC);
            F_S32(0x50) = 0;
            F_S16(0xE) -= 0x12;
            F_U8(0x6)++;
            return;
        }
        if (F_S32(0x84) == 1) {
            set_animation(self, 0xC);
            F_S32(0x50) = 0;
            F_S16(0xE) -= 0x12;
            F_U8(0x6)++;
            return;
        }
    } else if (func_800FA630(self, F_S16(0xA), F_S16(0xE) + 0x10) != 0 ||
               (F_U8(0x70) & 8) || F_S32(0x84) == 1) {
        set_animation(self, 0xC);
        F_S32(0x50) = 0;
        F_S16(0xE) += 0x12;
        F_U8(0x6)++;
        return;
    }
    move_object(self);
}
