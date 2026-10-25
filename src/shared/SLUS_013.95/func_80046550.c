#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002C9B0();
extern struct X4_PlayerObj g_Player;

void func_80046550(s8* arg0) {
    s8* p;
    s8* var_a1;

    if (arg0[2] == 0) {
        if (arg0[0x8F] != 0) {
            arg0[0x8F] = 0;
        }
        if (arg0[7] != 0) {
            return;
        }
        var_a1 = (s8*)&g_Player;
        if (var_a1[0xA6] == 2) {
            var_a1[0xA6] = 0;
        }
        ((u8*)var_a1)[0x98] = ((u8*)var_a1)[0x98] - 1;
        ((u8*)var_a1)[0x99] = ((u8*)var_a1)[0x99] - 1;
    } else {
        p = *(s8**)(arg0 + 0x7C);
        var_a1 = (s8*)(u32)(u8)p[7];
        if (p[7] != 0) {
            p[7] = (s32)var_a1 - 1;
        }
    }
    ((void (*)())func_8002C9B0)(arg0, var_a1);
}
