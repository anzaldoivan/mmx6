#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0();
s32 func_8002D2D4();

void func_800F82AC(u8* self) {
    u32 r;

    ((void (*)(void*))func_8002D2B0)(self);
    if (--*(s16*)(self + 0x7C) == 0) {
        if (--*(s16*)(self + 0x7E) == -1) {
            func_800179A4(self, 0x14);
            {
                register s32 t asm("$2") = self[5] + 1;
                self[5] = t;
            }
            return;
        }
        r = func_8002D2D4();
        self[5]--;
        *(u16*)(self + 0x7C) = (u8)(r % 30) + 60;
    }
}
