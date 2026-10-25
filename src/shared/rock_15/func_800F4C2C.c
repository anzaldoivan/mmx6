#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);

void func_800F4C2C(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 0x93) < 0x32) {
        M2C_FIELD(arg0, s8*, 0x93) = (s8)((u8)M2C_FIELD(arg0, s8*, 0x93) + 1);
        return;
    }
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
        // !FAKE: compare operand in v0 as retail
        register s32 a asm("$2") = M2C_FIELD(arg0, s16*, 0xE);
        var_v0 = a < M2C_FIELD(arg0, s16*, 0x94);
    } else {
        var_v0 = M2C_FIELD(arg0, s16*, 0xE) > M2C_FIELD(arg0, s16*, 0x94);
    }
    {
        u16 t = M2C_FIELD(arg0, u16*, 0x94);
        if (var_v0 != 0) {
            M2C_FIELD(arg0, s16*, 0xE) = t;
            M2C_FIELD(arg0, s8*, 0x93) = 0;
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    }
}
