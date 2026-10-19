#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
s32 func_801EE34C();

void func_800499A0(void* arg0) {
    s8* p = (s8*)arg0;

    if (p[0x5C] == 0) {
        u8* pl = (u8*)&D_800970A0;

        if (((s8*)pl)[0x8E] == 0) {
            p[0x5C] = 1;
        }
        if (pl[0x15] != ((u8*)p)[0x15]) {
            p[0x5C] = 1;
        }
        if (p[0x5C] == 0) {
            func_801EE34C(arg0, pl, p[2]);
        }
    }
}
