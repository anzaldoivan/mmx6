#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;

void func_800FC544(void* arg0) {
    s32 g;

    ((void (*)(void*, s32))func_800179A4)(arg0, 1);
    g = D_800970AA;
    if (M2C_FIELD(arg0, s16*, 0xA) < g) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    func_8002CCB0(arg0, 0x40, 0x40);
    func_80017A04(arg0);
    func_8002D230(arg0);
}
