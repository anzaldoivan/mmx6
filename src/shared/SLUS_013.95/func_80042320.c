#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D230();

void func_80042320(void* arg0) {
    s8 v;
    // !FAKE: pins the 0xE value to the first return register as retail allocates it
    register s32 e asm("$2");

    func_8002D230(arg0);
    e = *(s16*)((u8*)arg0 + 0xE);
    if (*(s16*)((u8*)arg0 + 0x86) <= e) {
        *(s16*)((u8*)arg0 + 0xE) = *(s16*)((u8*)arg0 + 0x86);
        v = *(s8*)((u8*)arg0 + 0x2);
        if (v == 0x31) {
            // !FAKE: keeps the two equality tests from folding into a range test
            goto set_b4;
        }
        if (v == 0x32) {
        set_b4:
            *(s16*)((u8*)arg0 + 0x7C) = 0xB4;
            *(u8*)((u8*)arg0 + 0x6) = 3;
        } else {
            *(s16*)((u8*)arg0 + 0x7C) = 0x3C;
            *(u8*)((u8*)arg0 + 0x6) = *(u8*)((u8*)arg0 + 0x6) + 1;
        }
    }
}
