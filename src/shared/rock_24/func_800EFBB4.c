#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EFBB4 (*(s32**)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80040488(M2C_UNK);
extern s8 D_800CCEF4;

void func_800EFBB4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_80016C48(2, 0x89, (s32)arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        M2C_FIELD(arg0, s16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, u8**, 0x3C) =
            (u8*)SPAD20_800EFBB4 +
            SPAD20_800EFBB4[func_8002A47C(M2C_FIELD(arg0, s8*, 1))];
        func_800179A4(arg0, 3);
        func_80040488(0);
        D_800CCEF4 = 1;
        {
            register s32 n asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = n;
        }
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}
