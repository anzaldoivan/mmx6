#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);   /* extern */
M2C_UNK func_8002EE10(void*); /* extern */

void func_800F76E0(void* arg0) {
    move_object(arg0);
    {
        // !FAKE: first flag read lands in the first return register (C0209)
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 0x70);
        if (t == 0) {
            func_8002EE10(arg0);
            if (M2C_FIELD(arg0, u8*, 0x70) == 0) {
                return;
            }
        }
    }
    M2C_FIELD(arg0, u8*, 0x94) = 1;
    M2C_FIELD(arg0, s16*, 0x88) = 0x3C;
    M2C_FIELD(arg0, u8*, 6)++;
}
