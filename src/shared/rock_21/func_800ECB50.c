#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCED1;

void func_800ECB50(void* arg0) {
    if ((D_800CCED1 >= 0x28) && ((u32)(M2C_FIELD(arg0, u8*, 2) - 0x28) >= 3U)) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
