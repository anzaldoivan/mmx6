#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();
void* func_8002C458();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern s8 D_8009723F;

void func_800FC1CC(void* arg0) {
    void* p;

    if (D_800970A5 == 0x14) {
        D_8009723F = 2;
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        p = alloc_class3_slot();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 1;
            M2C_FIELD(p, u8*, 1) = 0x18;
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
            M2C_FIELD(p, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = p;
        }
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = 0;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
