#include "common.h"

s32 func_8002D2D4();
void func_801EFB5C(void*, u8, u8);
extern u8 D_801F3998[];
extern u8 D_801F39AC[];

void func_801EF0FC(u8* arg0) {
    if (arg0[0x8D] < 3) {
        if (arg0[0x8D] == 0) {
            arg0[0x8E] = func_8002D2D4() % 6;
            arg0[0x8F] = func_8002D2D4() % 6;
            arg0[0x90] = func_8002D2D4() & 1;
        }
        if (arg0[0x15] == 0x40) {
            func_801EFB5C(
                arg0, (D_801F3998[arg0[0x8D] + arg0[0x8F] * 3] + arg0[0x90]),
                D_801F39AC[D_801F3998[arg0[0x8D] + arg0[0x8E] * 3]]);
        } else {
            register u8* b asm("$7");

            func_801EFB5C(
                arg0, (D_801F3998[arg0[0x8D] + arg0[0x8F] * 3] + arg0[0x90]),
                (b = D_801F39AC,
                 b -= -D_801F3998[arg0[0x8D] + arg0[0x8E] * 3])[3]);
        }
        arg0[0x8D]++;
    }
}
