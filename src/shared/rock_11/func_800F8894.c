#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F9E00(u8* arg0, u8 arg1);
extern s8 D_800CCF5C;

void func_800F8894(u8* arg0) {
    s8 state = *(s8*)(arg0 + 0x45);

    if (state == 1) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        if (D_800CCF5C / 2 >= *(s8*)(arg0 + 0x5C)) {
            func_800F9E00(arg0, 1);
        } else {
            func_800F9E00(arg0, 0);
        }
    } else if (state == 2) {
        set_animation(arg0, 1);
        {
            u32 r;
            {
                // !FAKE: depin: dropping it breaks the match (64/66)
                register s32 k asm("$2") = 0x5A;
                *(s16*)(arg0 + 0x7E) = k;
            }
            r = random_byte();
            arg0[6]--;
            *(u8*)(arg0 + 0x89) = r % 24 + 8;
        }
    }
}
