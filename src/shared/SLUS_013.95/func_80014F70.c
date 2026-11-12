#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libsnd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80015230(void);
void func_8001531C(void);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern s32 D_800C4564;
extern u8* D_800E0370;
extern u8 D_800E037A;

M2C_UNK func_80014F70(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    u8 sel = arg1;
    u8 i;
    s32* p;

    if (func_80064894(1, 0) != 0) {
        CdControlB(9, 0, 0);
    }
    if (D_8009509C != 0x80) {
        D_800E0380 = 0;
    }
    D_8009509C = 0;
    D_800E0379 = arg0;
    D_800E037A = sel;
    D_800E037C = arg2;
    D_8008EC08 = 0;
    D_800DF999 = 0;
    D_800DF998 = 0;
    D_800E01D4 = 0;
    D_800E01D6 = 0;
    for (i = 0; i < 0x20; i++) {
        D_800E01E8[i].pending = 0;
    }
    switch (D_800E037A) {
    case 0:
        D_800E0370 = (u8*)0x80103000;
        D_800E0374 = 0x1010;
        for (i = 0; i < 6; i++) {
            if (D_80090D50[i] != -1) {
                SsVabClose(D_80090D50[i]);
                D_80090D50[i] = -1;
            }
        }
        break;
    case 1:
        D_800E0370 = D_800E0368;
        break;
    case 2:
        D_800E0370 = (u8*)arg2;
        break;
    case 3:
        D_800E0370 = (u8*)D_800CD408;
        D_800E0374 = D_800C4564;
        for (i = 2; i < 6; i++) {
            if (i != 3) {
                if (D_80090D50[i] != -1) {
                    SsVabClose(D_80090D50[i]);
                    D_80090D50[i] = -1;
                }
            }
        }
        break;
    case 4:
        D_800E0374 = arg2;
        D_800E0370 = (u8*)D_800B91B8;
        if (D_80090D50[2] != -1) {
            SsVabClose(D_80090D50[2]);
            D_80090D50[2] = -1;
        } else {
            D_800E0374 = D_8009B798;
        }
        break;
    }
    p = rock_dat_file_table[arg0];
    D_800E01C0 = 1;
    D_800E01A8 = p[1];
    D_800E01B4 = p[0];
    func_800648B4((X4_CdlCB)func_8001531C);
    func_80015230();
}
