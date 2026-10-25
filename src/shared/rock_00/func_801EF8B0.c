#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002C9B0();
extern M2C_UNK g_Player;

void func_801EF8B0(s8* arg0) {
    s8 t;
    u8* p;
    u8* q;

    t = arg0[1];
    *(s32*)(arg0 + 0x50) = 0;
    *(s32*)(arg0 + 0x68) = 0;
    arg0[3] = 0;
    arg0[0x9D] = 0;
    if (t == 0x2) {
        if (*(s16*)(arg0 + 0x8A) == 0) {
            p = (u8*)&g_Player;
            p[0x98]--;
            p[0x99]--;
            func_8002C9B0(arg0);
        }
    } else if (t == 0x34) {
        q = *(u8**)(arg0 + 0x7C);
        (*(s16*)(q + 0x8A))--;
        func_8002C9B0(arg0);
    }
}
