#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D380(void*, void*);
extern M2C_UNK D_800970A0;
extern u8 D_800F3484[];

void func_800ED164(void* arg0) {
    void* g;

    if (--((s8*)SPAD4C)[0x80] != 0) {
        return;
    }
    g = &D_800970A0;
    if (M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA) > 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    SPAD4C[0x85] = func_8002D380(arg0, g);
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        SPAD4C[0x85] = D_800F3484[(s8)SPAD4C[0x85]];
    }
    switch ((s8)SPAD4C[0x85] & 0xFE) {
    case 2:
    case 4:
    case 6:
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    case 10:
    case 12:
    case 14:
        if ((s8)SPAD4C[0x85] >= 10) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        func_800179A4(arg0, 4);
        break;
    case 8:
        func_800179A4(arg0, 2);
        break;
    case 18:
    case 20:
    case 22:
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    case 26:
    case 28:
    case 30:
        if ((s8)SPAD4C[0x85] >= 0x1A) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
        func_800179A4(arg0, 5);
        break;
    case 24:
        func_800179A4(arg0, 3);
        break;
    case 0:
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        break;
    case 16:
        func_800179A4(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        break;
    }
    M2C_FIELD(arg0, u8*, 6)++;
}
