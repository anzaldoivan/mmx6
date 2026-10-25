#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800FA644(void* arg0) {
    s8 kind;
    s32 hi;
    // !FAKE: depin: dropping it breaks the match (49/51)
    register s32 flags asm("$3");
    s8 mode;

    kind = M2C_FIELD(arg0, s8*, 0x2);
    hi = kind & 0xF0;
    if (kind == 0) {
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        ((void (*)(void*, s32))func_800179A4)(arg0, 4);
        flags = M2C_FIELD(arg0, u16*, 0x42);
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        M2C_FIELD(arg0, u8*, 0x4) = 1;
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        goto end;
    }
    if (hi == 0x10) {
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x1F);
        flags = M2C_FIELD(arg0, u16*, 0x42);
        mode = 1;
        M2C_FIELD(arg0, s16*, 0x54) = 0;
        M2C_FIELD(arg0, u8*, 0x3) = mode;
        M2C_FIELD(arg0, u8*, 0x4) = mode;
        goto set5;
    }
    if (hi == 0x20) {
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x21);
        do {
            flags = M2C_FIELD(arg0, u16*, 0x42);
        } while (0);
        mode = 1;
        M2C_FIELD(arg0, u8*, 0x3) = mode;
        M2C_FIELD(arg0, u8*, 0x4) = mode;
        mode = 2;
    set5:
        M2C_FIELD(arg0, u8*, 0x5) = mode;
    end:
        do {
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        } while (0);
        M2C_FIELD(arg0, u16*, 0x42) = flags & 0x7FFF;
    }
}
