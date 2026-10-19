#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK);
extern u8 func_801F3698[];

M2C_UNK func_801EBF28(void* arg0) {
    func_8003BA04(arg0, func_801F3698[M2C_FIELD(arg0, s8*, 0x96)]);
}
