#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
s32 func_80065944(s32);
s32 func_80065A14(s32);

void func_800F8130(void* self) {
    register s32 ang asm("$16");
    s32 spd;

    func_800179A4(self, 0x12);
    M2C_FIELD(self, u8*, 0x3) = 1;
    if (M2C_FIELD(self, u8*, 0x15) == 0) {
        ang = func_8002D2D4() * 4 + 0x400;
    } else {
        ang = func_8002D2D4() * 4;
    }
    do {
        register s32 m asm("$2") = func_8002D2D4() & 0x1F;
        spd = m + 0x20;
    } while (0);
    M2C_FIELD(self, s16*, 0xA) += (func_80065A14(ang) * spd) >> 12;
    {
        s32 t =
            M2C_FIELD(self, u16*, 0xE) + ((-func_80065944(ang) * spd) >> 12);
        do {
        } while (0);
        M2C_FIELD(self, s16*, 0xE) = t;
    }
    M2C_FIELD(self, u8*, 0x5)++;
}
