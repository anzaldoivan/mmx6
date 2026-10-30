#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800EE8D4(void* arg0) {
    func_80017A04(arg0);
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s8*, 6) >= 5) {
        set_animation(arg0, 6);
        {
            // !FAKE: depin: dropping it breaks the match (21/24)
            register s32 a asm("$2") = M2C_FIELD(arg0, u8*, 0);
            s32 b = M2C_FIELD(arg0, u8*, 5);
            M2C_FIELD(arg0, u8*, 0) = a & 0xEF;
            M2C_FIELD(arg0, u8*, 5) = b + 1;
        }
    }
}
