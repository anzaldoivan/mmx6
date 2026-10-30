#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

void func_800F398C(s8* arg0) {
    if (*(u8*)(arg0 + 0x47) == 0) {
        s32 g = D_800970AA;

        if (*(s16*)(arg0 + 0xA) < g) {
            arg0[0x15] = 0x40;
        } else {
            arg0[0x15] = 0;
        }
        play_sound(2, 0x14, arg0);
        play_sound(2, 0x40, arg0);
        func_800F0434(arg0, 0x1D);
        arg0[6] = 0xA;
    }
}
