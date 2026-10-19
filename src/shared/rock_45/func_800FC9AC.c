#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
M2C_UNK func_80030ECC(void*);
extern s32 D_800FCA84;
extern s32 D_800FCE58;
extern s32 D_800FCE5C;

void func_800FC9AC(void* arg0) {
    s32 t;

    if (D_800FCE5C != 0 || D_800FCE58 != 0) {
        M2C_FIELD(arg0, u8*, 0x4) = 2;
        return;
    }
    func_80030ECC(arg0);
    if (M2C_FIELD(arg0, s8*, 0x5) == 0) {
        if (M2C_FIELD(arg0, s32*, 0x8C) == 0x14) {
            M2C_FIELD(arg0, void**, 0x50) = (u8*)&D_800FCA84 + 0x3A8;
        }
        t = M2C_FIELD(arg0, s32*, 0x8C) + 1;
        M2C_FIELD(arg0, s32*, 0x8C) = t;
        if (t == 0x3C) {
            M2C_FIELD(arg0, u8*, 0x4) = 2;
        }
    }
    func_8002CCB0(arg0, 0x20, 0x100);
    func_80017A04(arg0);
    func_8002D2B0(arg0);
}
