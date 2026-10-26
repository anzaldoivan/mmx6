#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

void func_800E9F7C(void);
extern s8 D_800CCF08;

void func_800FA314(u8* arg0) {
    SetDispMask(1);
    func_800E9F7C();
    {
        // !FAKE: flag read lands in the first return register
        register s32 c asm("$2") = D_800CCF08;
        if (c == 0) {
            *(s16*)(arg0 + 8) = 0x8A;
            *(s16*)(arg0 + 0xA) = 4;
            *(s16*)(arg0 + 4) = 0;
        } else {
            *(s16*)(arg0 + 4) = 0xB4;
            *(s16*)(arg0 + 0xA) = 0;
        }
    }
    arg0[1]++;
}
