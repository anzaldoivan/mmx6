#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
extern s16 D_80097222;

void func_800F48E4(void* arg0) {
    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (32/36)
        register s32 t asm("$2") = M2C_FIELD(arg0, s16*, 0x8C);
        if (t != 0) {
            M2C_FIELD(arg0, s16*, 0x8C) = M2C_FIELD(arg0, u16*, 0x8C) - 1;
            ((void (*)(void*))move_object)(arg0);
            if (M2C_FIELD(arg0, s16*, 0x8C) != 0) {
                return;
            }
        }
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s16*, 0x8C) = 0xC;
    if (M2C_FIELD(arg0, s16*, 0xE) < D_80097222 + 0x78) {
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
    } else {
        M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
