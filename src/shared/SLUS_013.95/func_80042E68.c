#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80042E68(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 0) != 0) {
        var_v0 = 0;
        if (M2C_FIELD(arg0, s8*, 1) != 4) {
            return var_v0;
        }
        if (M2C_FIELD(arg0, s8*, 3) != 0) {
            var_v0 = 1;
            if (M2C_FIELD(arg0, s8*, 7) == 1) {
                return var_v0;
            }
        }
    }
    return 0;
}
