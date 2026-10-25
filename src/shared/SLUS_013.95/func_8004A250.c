#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002C9B0();
M2C_UNK func_8002CB50();
M2C_UNK move_object(void*);

M2C_UNK func_8004A250(void* arg0) {
    ((void (*)())func_80017A04)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        ((M2C_UNK(*)())func_8002C9B0)(arg0);
    } else {
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            move_object(arg0);
        }
        func_8002CB50(arg0);
    }
}
