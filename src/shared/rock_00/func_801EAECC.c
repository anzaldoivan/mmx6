#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK player_spawn_visual(M2C_UNK, M2C_UNK, s8, M2C_UNK);

void func_801EAECC(u8* arg0) {
    s32 v;
    u16 flags;

    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        arg0[0x15] = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        arg0[0x15] = 0x40;
    }
    if (((s8*)arg0)[0x46] != 0) {
        return;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 0x180) {
        if (++arg0[0xD9] < 0x78) {
            return;
        }
    }
    play_sound(1, 5, arg0);
    flags = M2C_FIELD(arg0, u16*, 0x7C);
    if (flags & 4) {
        func_8003BA04(arg0, 0xBE);
        v = M2C_FIELD(arg0, s32*, 0x108);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = v * 2;
    } else if (flags & 8) {
        func_8003BA04(arg0, 0xBF);
        v = M2C_FIELD(arg0, s32*, 0x108);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = -v * 2;
    } else {
        func_8003BA04(arg0, 0xC0);
        {
            // !FAKE: depin: dropping it breaks the match (86/88)
            register s32 t asm("$2") = arg0[0x15];
            if (t != 0) {
                v = M2C_FIELD(arg0, s32*, 0x108) * 2;
            } else {
                v = -M2C_FIELD(arg0, s32*, 0x108) * 2;
            }
        }
        M2C_FIELD(arg0, s32*, 0x20) = v;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    arg0[0x8C] = 1;
    arg0[0x7A] = 1;
    arg0[6]++;
    player_spawn_visual(0x21, 0x19, 0, 0);
}
