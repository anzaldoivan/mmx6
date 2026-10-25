#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);

#define B8(o) (*(s8*)(arg0 + (o)))
#define U8(o) (*(u8*)(arg0 + (o)))
#define H16(o) (*(s16*)(arg0 + (o)))
#define W32(o) (*(s32*)(arg0 + (o)))

void func_800F4740(s32 arg0) {
    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (35/39)
        register s32 t asm("$2") = B8(0x92);
        if (t != 0) {
            B8(0x92) = U8(0x92) - 1;
            return;
        }
    }
    if (H16(0x8C) != 0) {
        H16(0x8C) = H16(0x8C) - 1;
        move_object(arg0);
    }
    if ((U8(0x70) & 1) || (H16(0x8C) == 0)) {
        W32(0x20) = 0xFFFE0000;
        H16(0x8C) = 0x30;
        B8(0x92) = 0x3C;
        U8(0x6) = U8(0x6) + 1;
    }
}
