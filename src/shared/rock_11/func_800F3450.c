#include "common.h"

void func_80013A48(s8 arg0);

void func_800F3450(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        func_80013A48(0x19);
        {
            // !FAKE: increment temp lands in the second return register as in retail
            register s32 t asm("$3") = arg0[6] + 1;
            arg0[6] = t;
        }
    }
}
