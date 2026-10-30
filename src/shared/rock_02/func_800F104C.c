#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

s32 func_8002A47C(s32);
void* alloc_sprite_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F104C(void* arg0) {
    void* s1;

    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        s1 = alloc_sprite_slot();
        if (s1 != 0) {
            M2C_FIELD(s1, u8*, 0) = 0x41;
            M2C_FIELD(s1, u8*, 1) = 0x10;
            M2C_FIELD(s1, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(s1, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(s1, u8*, 2) = 0;
            M2C_FIELD(s1, void**, 0x50) = arg0;
            M2C_FIELD(s1, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40) + 0x300;
            M2C_FIELD(s1, s16*, 0x42) =
                ((func_8002A47C(0x89) * 4 + 0x20) % 16) |
                (((func_8002A47C(0x89) + 8) / 4 + 0x1E0) << 6);
            M2C_FIELD(s1, s32*, 0x3C) =
                SPAD20 + *(s32*)(func_8002A47C(0x89) * 4 + SPAD20);
        }
        M2C_FIELD(arg0, u8*, 5)++;
    }
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
