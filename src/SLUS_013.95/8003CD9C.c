// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003CD9C);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003CDBC);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003CDF0);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003CE30(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xA1) = 0;
}
