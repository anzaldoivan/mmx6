#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002C458();
extern s32 D_800FCA84;

void func_800FA6EC(void* arg0) {
    s32 i;
    void* e;

    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        func_80016C48(2, 0x45, arg0);
        func_80012D9C(5);
    }
    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) == 0x50) {
        func_800179A4(arg0, 7);
        func_80016C48(2, 0x3B, arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        func_80016C48(2, 0x46, arg0);
        i = 0;
    loop: {
        s32 n;
        e = func_8002C458();
        n = i + 1;
        if (e != 0) {
            M2C_FIELD(e, u8*, 0) = 0x41;
            M2C_FIELD(e, u8*, 1) = 0x22;
            M2C_FIELD(e, u8*, 2) = 4;
            M2C_FIELD(e, void**, 0x7C) = arg0;
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - n * 0x24;
            } else {
                M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + n * 0x24;
            }
        }
        i = n;
    }
        if (i < 8) {
            goto loop;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_800179A4(arg0, 1);
        {
            u8* tb = ((u8*)&D_800FCA84 + 0x28C);
            register u8* q asm("$3") = M2C_FIELD(arg0, u8*, 0x8B)++ +
                                       M2C_FIELD(arg0, u8*, 0x8A) * 6 + tb;
            u8 v = *q;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
            M2C_FIELD(arg0, u8*, 0x5) = v;
        }
    }
}
