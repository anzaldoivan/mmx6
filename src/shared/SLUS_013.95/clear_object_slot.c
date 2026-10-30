#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

// 0x8002C9B0 clear_object_slot: zeroes the first eight bytes of an object slot.
// basis: code src/shared/SLUS_013.95/clear_object_slot.c:9 via=arg0
// callers: func_8002CA54, func_80033E00, func_80043018
void clear_object_slot(void* arg0) {
    M2C_FIELD(arg0, s8*, 0) = 0;
    M2C_FIELD(arg0, s8*, 1) = 0;
    M2C_FIELD(arg0, s8*, 2) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = 0;
    M2C_FIELD(arg0, s8*, 5) = 0;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
}
