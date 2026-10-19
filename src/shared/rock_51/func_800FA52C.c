#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(u8**)0x1F800028)

s32 func_800EA480(s8* arg0);
M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;
extern s16 D_800FCE08;

void func_800FA52C(void* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        __builtin_memcpy(&D_800FAA08, SPAD28 + 0xC00, 0x1200);
        D_800FCE08 = 0;
        func_8002B54C(&D_800FBC08, &D_800FAA08, 0x900, 0);
        func_8002B3D4(0x60, &D_800FBC08, 0x90);
        M2C_FIELD(arg0, u8*, 1) += 1;
    }
}
