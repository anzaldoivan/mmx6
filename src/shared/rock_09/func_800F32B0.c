#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8003D330();
extern s8 D_800CCF5C;

void func_800F32B0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x5C) < D_800CCF5C) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_80016C48(0, 0xE, 0);
            M2C_FIELD(arg0, s16*, 0x7C) = 3;
        }
        M2C_FIELD(arg0, s8*, 0x5C)++;
        func_80017A04(arg0);
        func_8002CCB0(arg0, 0x80, 0x80);
        return;
    }
    func_8003D330();
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s8*, 0x5) = 4;
    M2C_FIELD(arg0, s8*, 0x6) = 0;
}
