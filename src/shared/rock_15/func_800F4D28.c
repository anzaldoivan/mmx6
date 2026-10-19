#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();
extern M2C_UNK D_800F6F64;

void func_800F4D28(u8* arg0) {
    s16 mode;
    s32 vy;
    s8 st;

    func_80017A04();
    st = arg0[0x45];
    if (st == 1) {
        *(s32**)(arg0 + 0x50) = &D_800F6F64;
        arg0[6] = arg0[7];
        mode = *(s16*)(arg0 + 0x90);
        if (mode == 0) {
            vy = 0xFFFD0000;
            // !FAKE: m2c block order, both vertical arms share the store block
            goto vert;
        }
        if (mode == st) {
            vy = 0x30000;
        vert:
            *(s32*)(arg0 + 0x20) = 0;
            *(s32*)(arg0 + 0x24) = vy;
            return;
        }
        {
            // !FAKE: retail keeps the compare constant in the first return register
            register s32 k asm("$2") = 2;
            // !FAKE: depin: dropping it breaks the match (29/32)
            register s32 h asm("$2");
            if (mode == k) {
                h = 0xFFFE0000;
            } else {
                h = 0x20000;
            }
            *(s32*)(arg0 + 0x20) = h;
        }
        *(s32*)(arg0 + 0x24) = 0;
    }
}
