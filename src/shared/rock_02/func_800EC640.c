#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800EC640(void* arg0) {
    if (--((s8*)SPAD4C)[0x80] == 0) {
        switch (((s8*)SPAD4C)[0x85] & 0xFE) {
        case 2:
        case 4:
        case 6:
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        case 10:
        case 12:
        case 14:
            if (((s8*)SPAD4C)[0x85] >= 10) {
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
            if (((s8*)SPAD4C)[0x85] >= 26) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            func_800179A4(arg0, 5);
            break;
        case 24:
            func_800179A4(arg0, 3);
            break;
        case 0:
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            break;
        case 16:
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            break;
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
