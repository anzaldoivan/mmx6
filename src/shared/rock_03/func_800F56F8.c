#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800F7DE4;
extern s32 D_800F7DE8;
extern s32 D_800F7E30;

void func_800F56F8(void* arg0) {
    if (D_800F7DE4 != 0 || D_800F7DE8 != 0 || D_800F7E30 != 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    } else if (M2C_FIELD(arg0, u8*, 0x70) != 0 || func_80031474(arg0) < 0 ||
               func_80030ECC(arg0) != 0) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4) = 2;
    } else {
        func_80017A04(arg0);
        func_8002D230(arg0);
        func_8002CCB0(arg0, 0x10, 0x10);
    }
}
