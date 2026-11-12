#include "common.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

void func_8002D230();
void func_800FF0F8();
void func_800179A4(void*, s32);

void func_800FD344(void* p) {
    func_8002D230();
    if (M2C_FIELD(p, s32*, 0x24) <= 0) {
        func_800FF0F8(p);
        func_800179A4(p, 8);
        M2C_FIELD(p, u8*, 6)++;
    }
}
