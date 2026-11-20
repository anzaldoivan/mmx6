// rolefeed (3.1 T4): func_800EC970 of src/rock_10/E9860.c

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800FA900[];

void func_800EC970(struct ObjectHeader* arg0) {
    if (D_8009716C == 0) {
        ((void (**)(void*))(D_800FA900 + 0x16B0))[arg0->state](arg0);
    }
}
