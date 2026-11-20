// rolefeed (3.1 T4): func_800F87D4 of src/rock_11/E9860.c
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
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800FA4C8(struct X4_MainObj* self);
extern u8 D_800E9B80[];

void func_800F87D4(void* arg0) {
    u16 tbl[4];
    u32 r;

    __builtin_memcpy((u8*)tbl, (u8*)D_800E9B80, 8);
    func_800FA4C8(arg0);
    set_animation(arg0, 1);
    M2C_FIELD(arg0, u16*, 0x7C) = tbl[D_800CCF5F];
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    r = random_byte();
    M2C_FIELD(arg0, u8*, 6)++;
    M2C_FIELD(arg0, u8*, 0x89) = r % 24 + 8;
}
