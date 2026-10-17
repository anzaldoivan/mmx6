#include "common.h"

void func_800F02A0(u8, s8, s32, s16);
extern s8 D_800CCEF8;
extern u16 D_800F36CC;
extern u8 D_800F3844[];
extern u16 D_800F48EC;
extern s16 D_800F48EE;
extern s16 D_800F48F0;
extern u8 D_800F48F9;

void func_800EF3D8(u8* arg0) {
    u8* p;

    p = D_800F3844;
    func_800F02A0((p - -((D_800F48F9 + 7) * 3))[1], 2, 0x48, 0xAF);
    func_800F02A0((p - -((D_800F48F9 + 7) * 3))[2], 2, 0xDC, 0xAF);
    D_800F48F0 = 2;
    D_800F48EE = 0;
    D_800CCEF8 = 1;
    D_800F48EC = D_800F36CC;
    arg0[2]++;
}
