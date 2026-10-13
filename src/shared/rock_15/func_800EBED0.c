#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
M2C_UNK func_80017A04();
void func_800EBED0(void* arg0) {
    register s32 t asm("$2");
    func_80017A04(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C) - 1;
    M2C_FIELD(arg0, u16*, 0x7C) = t;
    if ((t << 16) == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 2) {
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            return;
        }
        M2C_FIELD(arg0, u8*, 5) = 3;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
