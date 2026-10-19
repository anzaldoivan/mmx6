#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
s32 func_800EA480(s8* arg0);
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;
extern s16 D_800FCE08;

void func_800FA700(void* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        D_800FCE08 += 2;
        ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
            &D_800FBC08, &D_800FAA08, 0x900, D_800FCE08);
        func_8002B3D4(0x60, &D_800FBC08, 0x90);
        if (D_800FCE08 >= 0x20) {
            M2C_FIELD(arg0, u16*, 4) = 0;
            M2C_FIELD(arg0, u8*, 1) += 1;
        }
    }
}
