#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8003D330();
s32 func_80040498();
extern s8 D_800CCF5C;

void func_800F4C74(s8* arg0) {
    if (func_80040498() == 0) {
        // !FAKE: counter read lands in v1 as retail
        register s32 cnt asm("$3") = arg0[0x5C];
        if (cnt < D_800CCF5C) {
            if (--*(s16*)(arg0 + 0x7C) == 0) {
                play_sound(0, 0xE, 0);
                *(u16*)(arg0 + 0x7C) = 3;
            }
            arg0[0x5C]++;
            func_80017A04(arg0);
            func_8002CCB0(arg0, 0x30, 0x40);
            return;
        } else {
            // !FAKE: places the limit arm after the shared tail as retail does
            goto limit;
        }
    }
    func_80017A04(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
    return;
limit:
    func_8003D330(D_800CCF5C);
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
    *(u16*)(arg0 + 0x7C) = 0;
    arg0[5] = 4;
    arg0[6] = 0;
}
