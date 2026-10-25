#include "common.h"

#define M2C_UNK s32
#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C3F8();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F0F4C(void* arg0) {
    void* temp_v0;
    s8 v;
    s32 t;

    t = M2C_FIELD(arg0, u16*, 0x7C) - 1;
    M2C_FIELD(arg0, u16*, 0x7C) = t;
    if ((t << 0x10) == 0) {
        temp_v0 = func_8002C3F8();
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s8*, 0) = -0x7F;
            M2C_FIELD(temp_v0, s8*, 1) = 0x1A;
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        if ((M2C_FIELD(arg0, s8*, 0x61) -= 5) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        v = M2C_FIELD(arg0, s8*, 0x61);
        {
            // !FAKE: depin: dropping it breaks the match (52/64)
            register s32 m asm("$2");

            if (v >= 6) {
                m = v;
                M2C_FIELD(arg0, s16*, 0x7E) = m;
            } else {
                m = 5;
                M2C_FIELD(arg0, s16*, 0x7E) = m;
            }
        }
    }
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
