#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002FF70(); /* extern */

s32 func_8003CA70(void*, s16);
void func_8003D394(void* arg0) {
    void* temp_a2;

    if (func_8002FF70() == 0x24) {
        temp_a2 = M2C_FIELD(arg0, void**, 0x68);
        ((s32(*)())func_8003CA70)(arg0,
                                  (s16)((M2C_FIELD(temp_a2, u8*, 3) +
                                         (M2C_FIELD(arg0, u16*, 0xE) +
                                          (s8)M2C_FIELD(temp_a2, u8*, 1))) &
                                        ~0xF),
                                  temp_a2);
    }
}
