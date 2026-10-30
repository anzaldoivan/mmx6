#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();

void func_800F56F8(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (16/26)
    register u16 t asm("$2");

    ((M2C_UNK(*)())func_80017A04)();
    func_800F82C0(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x3C) {
        set_animation(arg0, 9);
        t = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = t + 1;
    }
}
