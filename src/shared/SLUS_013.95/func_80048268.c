#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80048584(void*, u8);
extern u8 D_80077B44[];

void func_80048268(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (55/70)
    register s32 t asm("$2");

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), u8*, 0x16) != 0) {
        func_80048584(arg0, 0);
        {
            s8 c = M2C_FIELD(arg0, s8*, 2);
            t = 1;
            M2C_FIELD(arg0, u8*, 5) = t;
            t = 8;
            M2C_FIELD(arg0, u16*, 0x54) = t;
            if (c != 0) {
                M2C_FIELD(arg0, s16*, 0x42) = 0x7840;
                M2C_FIELD(arg0, s32*, 0x20) = 0x4000;
                M2C_FIELD(arg0, s32*, 0x24) = -0x8000;
                return;
            }
        }
        M2C_FIELD(arg0, s32*, 0x20) = -0x4000;
        M2C_FIELD(arg0, s32*, 0x24) = 0x8000;
        play_sound(0, 0xA, 0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0 && M2C_FIELD(arg0, u16*, 0x5C) == 0) {
        t = M2C_FIELD(arg0, u16*, 0x54);
        if (t != 0) {
            M2C_FIELD(arg0, u16*, 0x54) = t - 1;
            return;
        }
        func_80048584(arg0, D_80077B44[M2C_FIELD(arg0, u16*, 0x58)]);
        {
            t = M2C_FIELD(arg0, u16*, 0x58);
            M2C_FIELD(arg0, u16*, 0x58) = ++t;
            if ((u16)t >= 0xE) {
                M2C_FIELD(arg0, u16*, 0x58) = 0;
                M2C_FIELD(arg0, u16*, 0x5C) = 1;
            }
        }
    }
}
