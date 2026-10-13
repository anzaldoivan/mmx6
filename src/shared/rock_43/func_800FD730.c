#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
extern s32 D_800FDE30;
extern s32 D_800FE294;

void func_800FD730(void* arg0) {
    if ((M2C_FIELD(&D_800FDE30, s32*, 0x460) != 0) || (D_800FE294 != 0)) {
        M2C_FIELD(arg0, u8*, 4) += 1;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, u8*, 4) += 1;
    }
    func_8002CCB0(arg0, 0x30, 0x20);
    func_80017A04(arg0);
    func_8002D2B0(arg0);
}
