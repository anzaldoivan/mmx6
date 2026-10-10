#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800FD49C[])(void*);

#define F(type, off) (*(type*)((u8*)self + (off)))

void func_800F7284(void* self) {
    s8 s;
    s32 t;

    s = F(s8*, 0x7C)[4];
    if (s != 1) {
        F(s8, 4) = 2;
        F(s8, 3) = 0;
        return;
    }
    F(s32, 0x18) = F(s32, 0x8);
    F(s32, 0x1C) = F(s32, 0xC);
    ((void (*)(void*))func_80017A04)(self);
    D_800FD49C[F(s8, 5)](self);
    if (F(s8, 4) != s) {
        F(s8, 3) = 0;
        return;
    }
    if (func_80031474(self) < 0) {
        F(s8, 3) = 0;
        F(s8, 4) = 2;
        return;
    }
    if (func_80030ECC(self) != 0) {
        t = F(s8, 2) & 0xF0;
        if (t == 0x50) {
            return;
        }
        if (t == 0x60) {
            F(s8, 3) = 0;
            func_80049E50(self);
            F(s8, 4) = 2;
            return;
        }
    }
    if (func_8002CBFC(self, 0x20, 0xB0) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
        return;
    }
    F(s8, 4) = 2;
}
#undef F
