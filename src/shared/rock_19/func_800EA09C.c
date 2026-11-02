#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCF08;

void func_800EA09C(struct ObjectHeader* arg0) {
    s32 v = D_800CCF08;

    if (v == 1) {
        arg0->on_screen = v;
        return;
    }
    arg0->on_screen = 0;
}
