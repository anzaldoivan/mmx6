#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
extern s32 D_800F4148;

void func_800F2A9C(void* arg0) {
    ((void (*)())func_80017A04)();
    if (SPAD[0x8B] == 0) {
        M2C_FIELD(arg0, s32**, 0x68) = &D_800F4148;
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
