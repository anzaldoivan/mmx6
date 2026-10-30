#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230(void*);
void func_800EF0B0(void*, s32);
extern s8 D_800CCF5C;
#define D_800CCF5C_U (*(u8*)&D_800CCF5C)

void func_800ED234(void* arg0) {
    s32 n;
    s32 i;
    s8 hp;
    s8 max;
    // !FAKE: depin: dropping it breaks the match (67/70)
    register s32 f asm("$2");

    func_8002D230(arg0);
    f = M2C_FIELD(arg0, u8*, 0x70);
    if (f & 8) {
        play_sound(2, 0x82, arg0);
        max = D_800CCF5C_U;
        hp = M2C_FIELD(arg0, s8*, 0x5C);
        if (max * 3 / 4 < hp) {
            n = 4;
        } else if (max / 2 < hp) {
            n = 8;
        } else if (max / 4 < hp) {
            n = 0xC;
        } else {
            n = 0x10;
        }
        if (n != 0) {
            i = n;
            do {
                play_sound(2, 0x83, arg0);
                func_800EF0B0(arg0, 0x30);
                i--;
            } while (i != 0);
        }
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u16*, 0x84) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
#undef D_800CCF5C_U
