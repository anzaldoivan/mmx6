#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800F6714[])(void*);
extern void* D_800F70E4;

void func_800ED34C(void* arg0) {
    s32 r;
    s8 one;
    u16 t;

    one = M2C_FIELD(D_800F70E4, s8*, 4);
    if (one != 1) {
        M2C_FIELD(arg0, s8*, 4) = 4;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    func_80017A04(arg0);
    {
        s32 i = M2C_FIELD(arg0, s8*, 5) * 4;
        (*(void (**)(void*))((s8*)D_800F6714 + i))(arg0);
    }
    M2C_FIELD(arg0, s8*, 0x88) = 0;
    r = func_80031474(arg0);
    if (r < 0) {
        t = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(arg0, u16*, 0x86) = t;
        M2C_FIELD(arg0, u16*, 0xE) = t - 0x40;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x86) - 0x20;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x86) + 0x20;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x86) + 0x40;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x86);
        func_80049E50(arg0);
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 4;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (r > 0) {
        M2C_FIELD(arg0, s8*, 0x88) = one;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x20, 0x80) == one) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 4;
    }
}
