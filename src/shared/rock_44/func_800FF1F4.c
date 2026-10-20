#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
extern s16 D_80097222;

void func_800FF1F4(void* arg0) {
    func_80017A04(arg0);
    ((void (*)(void*))func_8002D2B0)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x70) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_80097222 + 0x70;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFA0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x100;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
