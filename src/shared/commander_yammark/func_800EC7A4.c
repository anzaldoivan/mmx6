#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK apply_object_motion(void*);

void func_800EC7A4(u8* arg0) {
    animate_object();
    apply_object_motion(arg0);
    {
        // !FAKE: keep the decremented counter in the first return register
        register s32 t asm("$2") = arg0[0x80] - 1;
        arg0[0x80] = t;
        if (!(t & 0xFF)) {
            *(s32*)(arg0 + 0x20) = 0;
            *(s32*)(arg0 + 0x28) = 0;
            arg0[7]++;
        }
    }
}
