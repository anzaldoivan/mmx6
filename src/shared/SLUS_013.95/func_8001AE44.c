#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#include "psyq/libpress.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001B520(void);
void func_8001B5FC(void);
void func_8001B900(s32 arg0);
void func_8001B90C(u32 arg0);
int func_800617A4(X4_CdlLOC* p);
void func_800646E4(s32, u8*);
s8 func_80064874(M2C_UNK, u8*);
void func_8001B428(void);
void func_8001BA04(void);
extern s32 D_80070CBC;
extern M2C_UNK D_800E2E64;
extern s32 D_800E2EB0;
extern s32 D_800E2EC0[];
extern s32 D_800E2EC8;
extern s32 D_800E2ECC;
extern s32 D_800E2ED0;
extern s32 D_800E2ED4;
extern s32 D_800E2ED8;
extern s32 D_800E2EE8[];
extern s32 D_800E2F08;
extern volatile s32 D_800E2F2C;
extern u8 D_800E2F40;
extern u8 D_800E2F45;
extern s32 D_800E2F48;
extern u8 D_800E2F58;

s32 func_8001AE44(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                  s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s32 sp18;
    s32* sp1C;
    s32 sp20;
    s32 y;
    u32 i;

    sp20 = 0x148;
    D_800E2EC0[0] = arg5;
    D_800E2EC0[1] = arg6;
    D_800E2ECC = arg2;
    D_800E2EB0 = 0;
    D_800E2F2C = 0;
    D_800E2ED8 = 0;
    D_800E2F08 = 0;
    D_800E2EC8 = arg7;
    D_800E2ED0 = arg9;
    D_800E2ED4 = arg9;
    D_80070CBC = arg8;
    func_8001B900(0);
    DecDCTReset(0);
    DecDCToutCallback(func_8001B428);
    StSetRing((unsigned long*)arg3, arg4);
    StSetStream(D_800E2ED0, arg1, 0x0FFFFFFF, func_8001BA04, 0);
    func_8001B5FC();
    *(u8*)&D_800E2E64 = 1;
    func_8001B90C(0x7F);
    func_800646E4(arg0, &D_800E2F58);
    D_800E2F48 = arg0;
    if (D_80070CBC != 0) {
        sp20 = 0x1C8;
    }
    for (;;) {
        while (func_80064874(0, 0) != 2) {
            do {
            } while (CdReset(0) == 0);
            VSync(3);
        }
        if (CdControl(0xD, (u8*)&D_800E2E64, 0) != 0) {
            VSync(3);
            if (CdControlB(0x15, (u8*)&D_800E2F58, 0) != 0 &&
                CdRead2(sp20) != 0) {
                VSync(3);
                while (CdControl(0x11, 0, &D_800E2F40) == 0) {
                }
                break;
            }
        }
    }
    arg0 = func_800617A4((X4_CdlLOC*)&D_800E2F45);
    if ((u32)arg0 < (u32)(D_800E2F48 - 0x14)) {
        return 1;
    }
    if ((u32)(D_800E2F48 + 5) < (u32)arg0) {
        return 1;
    }
    i = 0;
    func_8001B520();
    while (StGetNext((unsigned long**)&sp18, (unsigned long**)&sp1C) != 0) {
        VSync(0);
        i++;
        if (i >= 0x259) {
            return 1;
        }
    }
    D_800E2EE8[0] = sp1C[0];
    D_800E2EE8[1] = sp1C[1];
    D_800E2EE8[2] = sp1C[2];
    D_800E2EE8[3] = sp1C[3];
    D_800E2EE8[4] = sp1C[4];
    D_800E2EE8[5] = sp1C[5];
    D_800E2F08--;
    D_800E2EE8[6] = sp1C[6];
    D_800E2EE8[7] = sp1C[7];
    ((u16*)D_800E2EE8)[8] = (((u16*)D_800E2EE8)[8] + 8) / 16 * 16;
    y = ((u16*)D_800E2EE8)[9] + 8;
    if (y < 0) {
        y = ((u16*)D_800E2EE8)[9] + 0x17;
    }
    ((u16*)D_800E2EE8)[9] = y & 0xFFF0;
    ((int (*)(unsigned long*, unsigned long*))DecDCTvlc)(
        (unsigned long*)sp18, (unsigned long*)D_800E2EC0[D_800E2ED8]);
    StFreeRing((unsigned long*)sp18);
    return 0;
}
