#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003B114(s32 arg0);          /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */

void func_800379AC(void* arg0) {
    s8 v;
    s8 r;

    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    v = M2C_FIELD(arg0, s8*, 0xCA);
    if (v > 0) {
        return;
    }
    if (v == 0) {
        M2C_FIELD(arg0, u8*, 0xA4) = 0;
        func_8003B114((s32)arg0);
    } else {
        if (v == -1) {
            func_8003BA04(arg0, 0x25);
            r = -2;
        } else {
            if (M2C_FIELD(arg0, s8*, 0x46) >= 0) {
                return;
            }
            func_8003BA04(arg0, 0x24);
            r = 1;
        }
        M2C_FIELD(arg0, s8*, 0xCA) = r;
    }
}
