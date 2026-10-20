#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
extern s16 D_80097222;

void func_800FF6D0(void* arg0) {
    u8* sp;

    sp = SPAD4C;
    if (M2C_FIELD(sp, s8*, 0x89) == 0) {
        M2C_FIELD(sp, s8*, 0x89) = 0x78;
    }
    func_80017A04(arg0);
    ((void (*)(void*))func_8002D2B0)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x74) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_80097222 + 0x74;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFA0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x1000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
