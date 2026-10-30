#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800FA4C8(struct X4_MainObj* self);
extern u8 D_800CCF5F;
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
