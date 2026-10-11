#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D380(void*, void*);
void func_800EC848(void*);
extern M2C_UNK D_800970A0;

void func_800ED5DC(void* arg0) {
    void* g;

    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 6)++;
    func_800179A4(arg0, 1);
    g = &D_800970A0;
    {
        register u8** b asm("$2") = &SPAD4C;
        register s32 k asm("$3") = 0x14;
        register u8* p asm("$5") = *b;
        register u8* q asm("$4");
        p[0x80] = k;
        q = *b;
        q[0x82] = 0;
    }
    if (M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA) > 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    SPAD4C[0x85] = func_8002D380(arg0, g);
    func_800EC848(arg0);
}
