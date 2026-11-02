#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001A5F8(struct ObjectHeader* arg0) {
    arg0->on_screen = 1;
}
