#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8003D330();
s32 func_80040498();
extern s8 D_800CCF5C;

void func_800F4588(void* arg0) {
    s32 t;
    s32 n;
    register s32 f asm("$3");

    if (func_80040498() != 0) {
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    f = M2C_FIELD(arg0, s8*, 0x5C);
    n = D_800CCF5C;
    if (f < n) {
        t = M2C_FIELD(arg0, u16*, 0x7C) - 1;
        M2C_FIELD(arg0, u16*, 0x7C) = t;
        if ((t << 0x10) == 0) {
            func_80016C48(0, 0xE, 0);
            M2C_FIELD(arg0, u16*, 0x7C) = 3;
        }
        M2C_FIELD(arg0, u8*, 0x5C) = M2C_FIELD(arg0, u8*, 0x5C) + 1;
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    func_8003D330(n);
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
    M2C_FIELD(arg0, u16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 5) = 4;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
