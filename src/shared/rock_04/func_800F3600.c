#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D2B0(void*);
M2C_UNK func_800F25A0();

void func_800F3600(u8* arg0) {
    func_8002D2B0(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (12/18)
        register s16 t asm("$2") = *(s16*)(arg0 + 0x7C) - 1;
        *(s16*)(arg0 + 0x7C) = t;
        if (t == 0) {
            func_800F25A0(arg0);
        }
    }
}
