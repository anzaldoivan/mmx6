#include "common.h"

/* The TU's own names for D_800F366C+0x54 (D_800F36B0[8]), +0x1280 and +0x1282
   (func_800E9B58.c); one symbol base lets cse derive the addresses from each other. */
extern u16 D_800F36B0[];
extern u16 D_800F48EC;
extern s16 D_800F48EE;

void func_800EEE70(u8* arg0) {
    D_800F48EE = 0;
    D_800F48EC = D_800F36B0[8];
    arg0[2]++;
}
