#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCF08;

void func_800FA2C4(s8* arg0) {
    s8* p = arg0;
    s8* bg = (s8*)D_800971F8;
    s32 t;

    t = *(u16*)(bg + 0x5E) + 0x10;
    *(u16*)(bg + 0x5E) = t;
    if ((s16)t >= 0x120) {
        *(u16*)(bg + 0x5E) = 0x120;
        if (D_800CCF08 == 0) {
            *(s16*)(p + 8) = 0x1B8;
            *(s16*)(p + 0xA) = 2;
        } else {
            *(s16*)(p + 8) = 0x1CD;
            *(s16*)(p + 0xA) = 2;
        }
        do {
        } while (0);
        p[1] = (u8)p[1] + 1;
    }
}
