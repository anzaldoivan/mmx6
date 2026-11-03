#include "common.h"
#include "mmx6/object.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA078(struct ObjectHeader* arg0) {
    if (D_800CCF08 == 0) {
        arg0->on_screen = 1;
        return;
    }
    arg0->on_screen = 0;
}
