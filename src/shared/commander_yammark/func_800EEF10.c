#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800F7808[])(void*);

void func_800EEF10(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    func_80017A04();
    D_800F7808[M2C_FIELD(arg0, s8*, 5)](arg0);
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 3) >= 2U) {
        func_8002CCB0(arg0, 0x40, 0x40);
    }
}
