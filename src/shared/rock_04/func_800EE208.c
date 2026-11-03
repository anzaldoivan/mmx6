#include "common.h"
#include "mmx6/object.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void (*D_800F6C34[])(void*);

void func_800EE208(struct ObjectHeader* arg0) {
    if (D_80097180 != 2) {
        D_800F6C34[arg0->state](arg0);
    }
}
