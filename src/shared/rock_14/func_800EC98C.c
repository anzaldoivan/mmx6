#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern u8 D_800970B5;

void func_800EC98C(void* arg0) {
    ((void (*)())func_80017A04)();
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        play_sound(1, 1, arg0);
        ((void (*)(M2C_UNK, M2C_UNK))func_8003D308)(0x16, D_800970B5);
        M2C_FIELD(arg0, u16*, 0x7C) = 0x28;
        {
            // !FAKE: pin the increment temp to the register retail uses
            register s32 t asm("$3") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}
