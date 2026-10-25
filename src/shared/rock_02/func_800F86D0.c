#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK move_object();

void func_800F86D0(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    {
        // !FAKE: test byte in the first return register
        register s32 t asm("$2") = (s8)arg0[7];
        if (t != 0) {
            arg0[7]--;
            return;
        }
    }
    move_object((s32)arg0);
}
