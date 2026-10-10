#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
extern void (*D_800F3CF8[])(s8*);

#define SCRATCH_4C (*(u8**)0x1F80004C)

void func_800E98C0(s8* arg0) {
    s32 r;

    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    func_80017A04();
    D_800F3CF8[arg0[5]](arg0);
    if ((u8)arg0[0x47] == 0xD || (u8)arg0[0x47] == 0x1B) {
        *(s32*)(arg0 + 0x54) = 0;
        *(s32*)(arg0 + 0x50) = 0;
    } else {
        *(s32*)(arg0 + 0x54) = 0;
        *(s32*)(arg0 + 0x50) = (s32)(SCRATCH_4C + 0x80);
    }
    r = func_80031474(arg0);
    if (r > 0 && (r == 2 || r == 0x37)) {
        SCRATCH_4C[0x84] = 1;
    }
    if (r < 0) {
        SCRATCH_4C[0x84] = 1;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0xA0, 0xA0) == 0) {
        if ((u8)arg0[0x47] == 0xD || (u8)arg0[0x47] == 0x1B) {
            arg0[3] = 0;
            return;
        }
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    arg0[4]++;
}
