#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class4_slot();
s32 random_byte();

void func_800EE258(void* arg0) {
    void* e;
    s32 r;

    M2C_FIELD(arg0, s8*, 5) = 0;
    do {
        e = alloc_class4_slot();
        if (e != 0) {
            M2C_FIELD(e, u8*, 0) = 0x41;
            M2C_FIELD(e, u8*, 1) = 7;
            r = random_byte();
            M2C_FIELD(e, s16*, 0xA) = 0x16F8;
            M2C_FIELD(e, s8*, 2) = r % 5 + 1;
            M2C_FIELD(e, s16*, 0xE) = 0x408 - M2C_FIELD(arg0, s8*, 5) * 0x90;
            M2C_FIELD(e, void**, 0x7C) = arg0;
        }
        M2C_FIELD(arg0, s8*, 5)++;
    } while (M2C_FIELD(arg0, s8*, 5) < 5);
    M2C_FIELD(arg0, s16*, 0x18) = 0;
    M2C_FIELD(arg0, s8*, 4)++;
}
