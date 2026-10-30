#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 start_rekkoha(u8* arg0);

s32 func_801EBE04(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, u8*, 0xDD) = 1;
    if (start_rekkoha(arg0) != 0) {
        return 1;
    }
    M2C_FIELD(arg0, u8*, 0xDD) = 0;
    return 0;
}
