#include "common.h"
#define M2C_UNK s32

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))
#define SCRATCH_1C (*(u8**)0x1F80001C)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CB50();
s32 func_8002D2D4();
extern M2C_UNK D_80077E34;

void func_800ECC78(void* arg0) {
    u8* s;

    FX(arg0, u8, 0x3) = 1;
    FX(arg0, s32, 0x38) = 0;
    s = SCRATCH_1C;
    FX(arg0, u8*, 0x3C) = s + FX(s, s32, 0x8);
    FX(arg0, void*, 0x30) = &D_80077E34;
    FX(arg0, s16, 0x40) = 0;
    if (FX(arg0, s8, 0x54) != 2) {
        FX(arg0, s16, 0x42) = 0x7805;
    } else {
        FX(arg0, s16, 0x42) = 0x7806;
    }
    if (FX(arg0, s8, 0x7) == 0) {
        FX(arg0, u8, 0x16) = 1;
    }
    func_800179A4(arg0, FX(arg0, s8, 0x54));
    {
        // !FAKE: depin: dropping it breaks the match (41/44)
        register s32 r asm("$2") = FX(arg0, u8, 0x4) + 1;
        FX(arg0, u8, 0x4) = r;
    }
    FX(arg0, s8, 0x7) = func_8002D2D4() & 1;
    func_8002CB50(arg0);
}
