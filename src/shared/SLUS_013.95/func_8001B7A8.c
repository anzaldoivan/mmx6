#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"

#define M2C_UNK s32

#include "mmx6/x4.h"

void func_8001B5FC(void);
X4_CdlCB func_800648B4(X4_CdlCB func);
void func_80064DD4(s32);
void DecDCTReset(s32);
void DecDCToutCallback(s32);

void func_8001B7A8(void) {
    u8 sp10;

    sp10 = 0x80;
    func_8001B5FC();
    DecDCTReset(0);
    do {

    } while (CdControlB(9, 0, 0) == 0);
    VSync(0);
    func_80064DD4(0);
    func_800648B4(0);
    DecDCToutCallback(0);
    StUnSetRing();
    do {

    } while (CdReset(0) == 0);
    VSync(3);
    do {

    } while (CdControl(0xE, (s32)&sp10, 0) == 0);
    VSync(3);
}
