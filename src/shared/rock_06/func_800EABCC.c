#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800743DC;
extern M2C_UNK D_800F369C;
extern M2C_UNK D_800F36A0;
extern M2C_UNK D_800F36A4;

void func_800EABCC(void* arg0) {
    switch (M2C_FIELD(arg0, s8*, 6)) {
    case 0:
        M2C_FIELD(arg0, s8*, 6)++;
        func_800179A4(arg0, 5);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
    case 1:
        if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
            M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A0;
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F36A0;
        }
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, s8*, 6)++;
            func_800179A4(arg0, 6);
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 1);
            M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A4;
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F369C;
            M2C_FIELD(arg0, s8*, 5) = 1;
            M2C_FIELD(arg0, s8*, 6) = 0;
            {
                // !FAKE: depin: dropping it breaks the match (68/79)
                register s32 l asm("$3") = M2C_FIELD(arg0, u8*, 0x80);
                M2C_FIELD(arg0, u8*, 0x82) = 0x78;
                M2C_FIELD(arg0, u8*, 0x80) = l & 0xFE;
            }
        }
        break;
    }
    func_80017A04(arg0);
}
