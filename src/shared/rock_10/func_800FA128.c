#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object(s32);
extern s16 D_80097202;

void func_800FA128(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (33/35)
    register s32 t asm("$3");

    move_object((s32)arg0);
    {
        // !FAKE: depin: dropping it breaks the match (33/35)
        register s32 s asm("$2") = *(u8*)(arg0 + 0x15);
        if (s == 0) {
            if (D_80097202 + 0x20 >= *(s16*)(arg0 + 0xA)) {
                t = *(u8*)(arg0 + 0x6);
                {
                    s32 c;
                    c = 0x20000;
                    *(s32*)(arg0 + 0x20) = c;
                    c = 0x40;
                    *(u8*)(arg0 + 0x15) = c;
                }
                goto block_5;
            }
        } else if (*(s16*)(arg0 + 0xA) >= D_80097202 + 0x120) {
            t = *(u8*)(arg0 + 0x6);
            *(s32*)(arg0 + 0x20) = 0xFFFE0000;
            *(u8*)(arg0 + 0x15) = 0;
        block_5:
            *(u8*)(arg0 + 0x6) = t + 1;
        }
    }
}
