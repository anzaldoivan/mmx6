#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
extern s16 D_800F6AF8;

void func_800F2708(u8* arg0) {
    register s32 t asm("$2");

    func_80017A04();
    func_8002D2B0(arg0);
    t = *(s32*)(arg0 + 0x20);
    if (t > 0) {
        if (D_800F6AF8 + 0x880 < *(s16*)(arg0 + 0xA)) {
            arg0[0x15] = 0;
            if (*(s8*)(arg0 + 0x87) < 10) {
                arg0[0x87]++;
            }
            goto end;
        }
    } else if (*(s16*)(arg0 + 0xA) < D_800F6AF8 + 0x590) {
        arg0[0x15] = 0x40;
        if (*(s8*)(arg0 + 0x87) < 10) {
            arg0[0x87]++;
        }
    end:
        arg0[5] = 3;
        arg0[6] = 0;
    }
}
