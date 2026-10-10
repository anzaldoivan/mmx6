#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void (*D_800F5F7C[])(s8*);

void func_800F1E48(s8* arg0) {
    if (arg0[7] == 1) {
        arg0[5] = 7;
        arg0[6] = 0;
        arg0[7] = 0;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x82) != arg0[0x5C] && arg0[0x84] == 0) {
        arg0[5] = 8;
        arg0[6] = 0;
        arg0[0x84] = 1;
        return;
    }
    D_800F5F7C[arg0[6]](arg0);
}
