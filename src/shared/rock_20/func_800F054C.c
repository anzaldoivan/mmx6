#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80097169;
extern struct X4_EngineObj D_800CCED0;

#define ENG48 ((u8*)&D_800CCED0)

s32 func_800F054C(void) {
    u8* e = ENG48;
    u8 c = e[0x26];

    if ((u32)(c - 1) < 8U) {
        if (*(s8*)(e + 0x27) == 0) {
            if (!((D_80097169 >> ((s8)c - 1)) & 1)) {
                return 1;
            }
        }
    }
    return 0;
}
