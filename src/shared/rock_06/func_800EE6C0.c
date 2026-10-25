#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EE6C0(void* self) {
    // !FAKE: depin: dropping it breaks the match (83/90)
    register s32 flag asm("$5");
    s32 v;
    s32 bits;

    if (M2C_FIELD(self, u8*, 0x8D) != 0 || (M2C_FIELD(self, u8*, 0x97) & 2)) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x8E) == 0) {
        bits = M2C_FIELD(self, u16*, 0x8A) & 3;
        if ((u16)bits != 0 && (u16)bits != 3) {
            M2C_FIELD(self, u16*, 0x9A) = bits;
            M2C_FIELD(self, u8*, 0x8E) = 1;
            M2C_FIELD(self, u8*, 0x8F) = 0xC;
        }
        return;
    }
    if (M2C_FIELD(self, u16*, 0x9A) & M2C_FIELD(self, u16*, 0x8A)) {
        if (M2C_FIELD(self, s8*, 0x2) == 0) {
            v = M2C_FIELD(self, s8*, 0x5);
            if (v == 1) {
                goto zero;
            }
            if (v == 2) {
                goto zero;
            }
            if (v == 5) {
                goto zero;
            }
        one:
            flag = 1;
        } else {
            v = M2C_FIELD(self, s8*, 0x5);
            if (v == 0) {
                goto one;
            }
            if (v == 1) {
                goto zero;
            }
            if (v == 2) {
                goto zero;
            }
            if (v == 5) {
                goto zero;
            }
            if (v == 4) {
                goto zero;
            }
            if (v != 12) {
                goto one;
            }
        zero:
            flag = 0;
        }
        if (flag == 0) {
            if (M2C_FIELD(self, s8*, 0x67) == 0) {
                M2C_FIELD(self, u8*, 0x5) = 7;
                M2C_FIELD(self, u8*, 0x6) = 0;
                M2C_FIELD(self, u8*, 0x97) ^= 8;
                return;
            }
            if (M2C_FIELD(self, u8*, 0x7D) == 0) {
                M2C_FIELD(self, u8*, 0x5) = 0xF;
                M2C_FIELD(self, u8*, 0x6) = 0;
                M2C_FIELD(self, u8*, 0x97) ^= 8;
                return;
            }
        }
    }
    if (--M2C_FIELD(self, u8*, 0x8F) == 0) {
        M2C_FIELD(self, u8*, 0x8E) = 0;
    }
}
