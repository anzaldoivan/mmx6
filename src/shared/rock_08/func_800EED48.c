#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
extern void (*D_800F5B88[])(void*);

void func_800EED48(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    func_80017A04();
    D_800F5B88[M2C_FIELD(arg0, s8*, 5)](arg0);
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 3) >= 2U) {
        func_8002CCB0(arg0, 0x40, 0x40);
    }
}
