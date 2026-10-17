#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F9F7C(void* arg0, M2C_UNK arg1, M2C_UNK arg2);
extern u8 D_800CCF38;

void func_800F8D14(void* arg0) {
    func_800F9F7C(arg0, 0x10, 0);
    if (D_800CCF38 >= 2) {
        M2C_FIELD(arg0, u8*, 0x8B) = M2C_FIELD(arg0, u8*, 0x8B) + 2;
    } else {
        M2C_FIELD(arg0, u8*, 0x8B) = M2C_FIELD(arg0, u8*, 0x8B) + 1;
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
