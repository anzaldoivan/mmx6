#include "common.h"
#define M2C_UNK s32

s32 func_80021AF0(s32 arg0);
M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
extern u8 D_8006E468[];
extern u8 D_8006E484[];
extern u16 D_80090D6A;

void func_80022838(s32 arg0) {
    u8* temp_v0;

    temp_v0 = D_8006E484 + (D_8006E468[func_80021AF0(arg0)] << 5);
    if (D_80090D6A == 0) {
        func_8002B3D4(0x16, (M2C_UNK*)temp_v0, 1);
        return;
    }
    func_8002B3D4(0x5F, (M2C_UNK*)temp_v0, 1);
}
