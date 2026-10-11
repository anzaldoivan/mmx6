#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
s32 func_80065944(s32);
s32 func_80065A14(s32);

void func_800F73F0(void* arg0) {
    s32 ang;

    func_800179A4(arg0, (((u32)func_8002D2D4() % 3) & 0xFF) + 0x1D);
    if (func_8002D2D4() & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    ang = (M2C_FIELD(arg0, s32*, 0x84) + 0x800) & 0xFFF;
    M2C_FIELD(arg0, u16*, 0x90) = M2C_FIELD(arg0, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0x92) = M2C_FIELD(arg0, u16*, 0xE);
    M2C_FIELD(arg0, u16*, 0xA) =
        M2C_FIELD(arg0, u16*, 0x90) + (func_80065A14(ang) >> 3);
    M2C_FIELD(arg0, u16*, 0xE) =
        M2C_FIELD(arg0, u16*, 0x92) + (func_80065944(ang) >> 3);
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}
