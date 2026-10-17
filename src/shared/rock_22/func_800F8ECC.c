#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C3F8();

void func_800F8ECC(void* arg0) {
    void* temp_v0;
    s32 t;

    t = M2C_FIELD(arg0, u16*, 0x7C) - 1;
    M2C_FIELD(arg0, u16*, 0x7C) = t;
    if ((t << 0x10) == 0) {
        M2C_FIELD(arg0, u8*, 5) = 2;
        temp_v0 = func_8002C3F8();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x1A;
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        if ((M2C_FIELD(arg0, s8*, 0x61) -= 5) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        {
            s32 v = M2C_FIELD(arg0, s8*, 0x61);
            // !FAKE: clamp result lives in the first return register
            register s32 m asm("$2");
            // !FAKE: compare result shares the first return register
            register s32 c asm("$2");

            if ((c = v < 6) != 0) {
                m = 5;
            } else {
                m = v;
            }
            M2C_FIELD(arg0, s16*, 0x7E) = m;
        }
    }
    M2C_FIELD(arg0, u8*, 3) = 1;
}
