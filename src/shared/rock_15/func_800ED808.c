#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800F6758[])(s8*);
extern void* D_800F70E4;

void func_800ED808(s8* arg0) {
    s8 one;

    one = *((s8*)D_800F70E4 + 4);
    if (one != 1) {
        arg0[4] = 2;
        arg0[3] = 0;
        return;
    }
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    func_80017A04(arg0);
    D_800F6758[arg0[5]](arg0);
    if (arg0[4] != one) {
        arg0[3] = 0;
        return;
    }
    if (func_80031474(arg0) < 0) {
        arg0[3] = 0;
        func_80049E50(arg0);
        arg0[4] = 2;
        return;
    }
    func_80030ECC(arg0);
    if ((arg0[2] & 0xF0) == 0x30) {
        if (func_8002CBFC(arg0, 0x70, 0x30) != 0) {
            arg0[4] = 2;
            return;
        }
        goto call;
    }
    if (func_8002CBFC(arg0, 0x30, 0x30) == 0) {
        if ((arg0[2] & 0xF0) != 0x20) {
        call:
            func_8002CCB0(arg0, 0x20, 0x20);
        }
    } else {
        arg0[4] = 2;
    }
}
