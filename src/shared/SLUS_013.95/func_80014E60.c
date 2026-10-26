#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001531C(void);
void func_800165A4(void);
void func_800646E4(s32, u8*);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern u8 D_8009509C;
extern s32 D_800E01B4;
extern s32 D_800E01C0;
extern s32 D_800E01D0;
extern u8 D_800E01D8;

void func_80014E60(s32 arg0, s32 arg1) {
    u8 sp10;

    sp10 = 0xA0;
    D_8009509C = 0;
    D_800E01D0 = 0;
    func_800646E4(D_800E01B4, &D_800E01D8);
    {
        // !FAKE: depin: dropping it breaks the match (65/68)
        register s32 t asm("$3") = D_800E01B4 - 1;
        D_800E01B4 = t;
    }
    do {
    loop_1:
        while (func_80064894(1, 0) != 0) {
        }
        if (CdControl(0xE, (s32)&sp10, 0) == 0) {
            goto loop_1;
        }
        VSync(3);
    } while (CdControl(2, (s32)&D_800E01D8, 0) == 0);
    if (D_800E01C0 == 0) {
        func_800648B4((X4_CdlCB)func_800165A4);
    } else {
        func_800648B4((X4_CdlCB)func_8001531C);
    }
    while (CdControl(6, 0, 0) == 0) {
    }
    D_8009509C = 1;
}
