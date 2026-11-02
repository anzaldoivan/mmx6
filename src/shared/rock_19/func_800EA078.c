#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCF08;

void func_800EA078(struct ObjectHeader* arg0) {
    if (D_800CCF08 == 0) {
        arg0->on_screen = 1;
        return;
    }
    arg0->on_screen = 0;
}
