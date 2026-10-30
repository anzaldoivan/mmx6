#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(u8**)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;
extern s16 D_800FCE08;

void func_800FA0F4(void* arg0) {
    if ((s16)M2C_FIELD(arg0, u16*, 4)++ >= 0x3D) {
        D_800FCE08 -= 2;
        ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
            &D_800FBC08, &D_800FAA08, 0x900, D_800FCE08);
        load_palette(0x60, &D_800FBC08, 0x90);
        if (D_800FCE08 == 0) {
            __builtin_memcpy(&D_800FAA08, SPAD28 + 0xC00, 0x1200);
            D_800FCE08 = 0;
            func_8002B54C(&D_800FBC08, &D_800FAA08, 0x900, 0);
            load_palette(0x60, &D_800FBC08, 0x90);
            M2C_FIELD(arg0, u16*, 8) = 0xD5;
            M2C_FIELD(arg0, u16*, 0xA) = 0xB;
            M2C_FIELD(arg0, u16*, 4) = 0;
            M2C_FIELD(arg0, u8*, 1) += 1;
        }
    }
}
