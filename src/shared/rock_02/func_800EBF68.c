#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EB924(void*, void*); /* extern */
extern M2C_UNK D_80090C88;

void func_800EBF68(void* arg0) {
    u32 var_s0;

    var_s0 = arg0 + 0x9C;
    if (var_s0 < (u32)&D_80090C88) {
        do {
            if ((M2C_FIELD(var_s0, s8*, 0) != 0) &&
                (M2C_FIELD(arg0, s8*, 1) == M2C_FIELD(var_s0, s8*, 1))) {
                func_800EB924((void*)var_s0, arg0);
            }
            var_s0 += 0x9C;
        } while (var_s0 < (u32)&D_80090C88);
    }
}
