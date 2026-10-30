#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F86F8(u8* arg0) {
    s8 temp_s1;

    temp_s1 = *(s8*)(arg0 + 0x45);
    if (temp_s1 == 1) {
        play_sound(2, 0x52, arg0);
        set_animation(arg0, 8);
        {
            // !FAKE: depin: dropping it breaks the match (36/39)
            register void* p asm("$2") = &D_8007433C;
            *(void**)(arg0 + 0x58) = p;
        }
        do {
        } while (0);
        {
            void* a = &D_800FC734;
            // !FAKE: depin: dropping it breaks the match (33/39)
            register void* b asm("$3") = &D_800FC738;
            *(void**)(arg0 + 0x50) = a;
            arg0[0x8E] = temp_s1;
            *(void**)(arg0 + 0x54) = b;
            arg0[6] = 8;
        }
    } else if (temp_s1 == 2) {
        play_sound(2, 0x59, arg0);
    }
}
