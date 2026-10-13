#include "common.h"
#define M2C_UNK s32

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D2B0(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);

void func_800F35BC(void* arg0) {
    void* s1;
    s32 r;

    s1 = FLD(arg0, void*, 0x7C);
    ((void (*)())func_8002D2B0)();
    r = func_80031474(arg0);
    FLD(arg0, s32, 0x8C) = r;
    if (r < 0) {
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x90) = 0x3C;
        FLD(s1, u8, 0x7) = 1;
        return;
    }
    func_80030ECC(arg0);
    if (FLD(arg0, s16, 0x92) > FLD(arg0, s16, 0xE)) {
        func_8002D2B0(arg0);
        return;
    }
    func_80016C48(2, 0x36, s1);
    func_80012D9C(5);
    {
        register s32 t asm("$2") = FLD(arg0, u16, 0x92);
        register s32 c asm("$3") = 1;
        FLD(arg0, u8, 0x5) = c;
        c = 3;
        FLD(arg0, s16, 0xE) = t;
        FLD(s1, u8, 0x7) = c;
    }
}
