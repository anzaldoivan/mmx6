#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
void* alloc_class3_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F0A78(void* arg0);

void func_800F0120(void* arg0) {
    void* p;
    s32 v;
    s8 r;

    if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
        ((void (*)())func_800F0A78)();
        M2C_FIELD(arg0, s32*, 0x8C) = 3;
    }
    if (M2C_FIELD(arg0, s32*, 0x90) == 0) {
        func_80029478(0xA, 4, 2);
        {
            // !FAKE: depin: dropping it breaks the match (80/82)
            register s32 k asm("$2") = 0xA;
            M2C_FIELD(arg0, s32*, 0x90) = k;
        }
    }
    M2C_FIELD(arg0, s32*, 0x90)--;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 5)++;
        p = alloc_class3_slot();
        if (p != 0) {
            M2C_FIELD(p, s8*, 0) = -0x7F;
            M2C_FIELD(p, s8*, 1) = 0x1A;
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
            M2C_FIELD(p, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = p;
        }
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x60);
    if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        M2C_FIELD(arg0, s8*, 0x61) -= 5;
        if (M2C_FIELD(arg0, s8*, 0x61) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        r = M2C_FIELD(arg0, s8*, 0x61);
        v = r < 6;
        if (v != 0) {
            v = 5;
        } else {
            v = r;
        }
        M2C_FIELD(arg0, s16*, 0x7E) = v;
    }
}
