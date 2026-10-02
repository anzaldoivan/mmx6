#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012890(M2C_UNK); /* extern */
M2C_UNK func_80013DE8();        /* extern */
extern s8 D_80097428;

void func_8001ED88(void* arg0) {
    D_80097428 = 0;
    M2C_FIELD(arg0, s8*, 0) = 0x14;
    M2C_FIELD(arg0, s8*, 1) = 0;
    M2C_FIELD(arg0, s8*, 2) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 0x1F) = 0;
    M2C_FIELD(arg0, s8*, 0x24) = 0;
    M2C_FIELD(arg0, s8*, 0xC) = 0xB;
    M2C_FIELD(arg0, s8*, 0xD) = 0;
    func_80013DE8();
    func_80012890(1);
}
