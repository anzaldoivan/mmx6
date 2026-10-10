#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */

void func_800E9EF4(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, u8*, 0x15) =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), u8*, 0x15);
    switch (M2C_FIELD(arg0, s8*, 0x2)) {
    case 0:
        M2C_FIELD(arg0, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0xE) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s16*, 0xE);
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        break;
    case 1:
        M2C_FIELD(arg0, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0xE) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s16*, 0xE);
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xF);
        break;
    case 2:
        M2C_FIELD(arg0, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0xE) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s16*, 0xE);
        ((void (*)(void*, s32))func_800179A4)(arg0, 9);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0xC;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0xC;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE) - 0x1E;
        break;
    case 3:
        M2C_FIELD(arg0, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0xE) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s16*, 0xE);
        ((void (*)(void*, s32))func_800179A4)(arg0, 9);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0xC;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0xC;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE) + 0x1E;
        break;
    case 16:
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xB);
        break;
    case 17:
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xD);
        break;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
}
