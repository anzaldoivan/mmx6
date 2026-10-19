#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s32 D_800FBC70;
extern s32 D_800FBC74;

void func_800F14F0(void* arg0) {
    if (D_800FBC70 != 0 || D_800FBC74 != 0 ||
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 4) == 2) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x30, 0x20);
}
