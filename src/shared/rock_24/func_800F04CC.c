#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
void* func_8002C458();
s32 func_8002D2D4();
extern u8 D_800F7528[];
extern M2C_UNK D_800F77EC;

void func_800F04CC(void* arg0) {
    void* child;
    s16 t;

    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s8*, 7) = func_8002D2D4() % 5;
        if ((M2C_FIELD(arg0, s8*, 7) == 3) && (D_800F77EC != 0)) {
            M2C_FIELD(arg0, s8*, 7) -= 1;
        }
        if ((M2C_FIELD(arg0, s8*, 7) == 4) && (D_800F77EC != 0)) {
            M2C_FIELD(arg0, s8*, 7) -= 3;
        }
        child = func_8002C458();
        if (child != 0) {
            u8 b0 = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(child, u8*, 1) = 0x1A;
            M2C_FIELD(child, u8*, 0) = b0;
            b0 = M2C_FIELD(arg0, u8*, 7);
            M2C_FIELD(child, void**, 0x7C) = arg0;
            M2C_FIELD(child, u8*, 2) = b0 + 0x1E;
        }
    }
    t = ++M2C_FIELD(arg0, s16*, 0x7C);
    if (t == 22) {
        child = func_8002C458();
        if (child != 0) {
            u8 b0 = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(child, u8*, 1) = 0x1A;
            M2C_FIELD(child, u8*, 0) = b0;
            b0 = M2C_FIELD(arg0, u8*, 7);
            M2C_FIELD(child, void**, 0x7C) = arg0;
            M2C_FIELD(child, u8*, 2) = b0;
            func_80016C48(2, 0x8A, (s32)arg0);
        }
    } else if (t == 50) {
        u8 i = M2C_FIELD(arg0, u8*, 0x87)++;
        u8 v = D_800F7528[i + M2C_FIELD(arg0, u8*, 0x86) * 6];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}
