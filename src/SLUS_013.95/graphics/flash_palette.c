// prog SLUS_013.95 | system graphics | range 0x8003CE30-0x8003CE34
#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void clear_flash_palette(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xA1) = 0;
}
