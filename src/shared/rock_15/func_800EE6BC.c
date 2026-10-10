#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800ED484(void*);                   /* extern */
M2C_UNK func_800EF22C(void*, M2C_UNK);          /* extern */

void func_800EE6BC(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    switch (temp_v1) { /* irregular */
    case 1:
        func_80016C48(2, 0x23, arg0);
        func_80016C48(2, 0x86, arg0);
        func_800EF22C(arg0, 0x10);
        return;
    case 2:
        func_800ED484(arg0);
        return;
    }
}
