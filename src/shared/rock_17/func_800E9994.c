#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800E9994(void* arg0) {
    u8 idx;
    s8 i;
    s32 t;
    s32 w;
    u8 v;

    v = M2C_FIELD(arg0, u8*, 2);
    M2C_FIELD(arg0, u8*, 0) = 1;
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 0x37) = -1;
    M2C_FIELD(arg0, s16*, 0xA) = 0;
    M2C_FIELD(arg0, s16*, 0xE) = 0;
    if (!(v & 0x80)) {
        M2C_FIELD(arg0, s16*, 0x34) = 0x7FFF;
        M2C_FIELD(arg0, s16*, 0x4A) = 8;
        M2C_FIELD(arg0, s16*, 0x42) = 0x60;
        M2C_FIELD(arg0, s16*, 0x3A) = 0x60;
        M2C_FIELD(arg0, s16*, 0x46) = 0;
        M2C_FIELD(arg0, s16*, 0x3E) = 0;
        M2C_FIELD(arg0, u8*, 0x36) = 0x20;
        M2C_FIELD(arg0, u8*, 5) = 0;
    } else {
        idx = v & 0x7F;
        i = idx;
        M2C_FIELD(arg0, s16*, 0x34) = 0x2208;
        t = i * 6;
        M2C_FIELD(arg0, u8*, 2) = idx;
        M2C_FIELD(arg0, s16*, 0x4A) = 0x100;
        M2C_FIELD(arg0, s16*, 0x46) = t + 0xF0;
        M2C_FIELD(arg0, s16*, 0x42) = 0x100;
        M2C_FIELD(arg0, s16*, 0x3A) = 0x100;
        M2C_FIELD(arg0, s16*, 0x3E) = t + 0xF2;
        if (i >= 0x14) {
            switch (i - 0x14) {
            case 0:
            case 1:
            case 2:
                M2C_FIELD(arg0, u8*, 2) = idx + 1;
                break;
            default:
                w = M2C_FIELD(arg0, u8*, 2);
                M2C_FIELD(arg0, u8*, 2) = w + (w - 0x15);
                break;
            }
        }
        M2C_FIELD(arg0, u8*, 0x36) = 0;
        M2C_FIELD(arg0, u8*, 5) = 1;
    }
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 4)++;
}
