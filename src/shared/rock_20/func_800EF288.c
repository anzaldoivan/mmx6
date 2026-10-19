#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F48F2;
extern u8 D_800F48F3;
extern u8 D_800F48F4;
extern u8 D_800F48F5;
extern u8 D_800F48F8;

void func_800EF288(u8* arg0) {
    u8* e = (u8*)&D_800CCED0;
    if (e[0x69] != e[0xC8]) {
        D_800F48F4 = 1;
    } else {
        D_800F48F4 = 0;
    }
    D_800F48F2 = 0;
    D_800F48F3 = 0;
    D_800F48F5 = 0;
    D_800F48F8 = 0;
    arg0[2]++;
}
