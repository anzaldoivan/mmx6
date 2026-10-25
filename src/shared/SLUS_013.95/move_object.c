#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void move_object(void* arg0) {
    M2C_FIELD(arg0, s32*, 8) =
        (s32)(M2C_FIELD(arg0, s32*, 8) + M2C_FIELD(arg0, s32*, 0x20));
    M2C_FIELD(arg0, s32*, 0xC) =
        (s32)(M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg0, s32*, 0x24));
}
