#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libspu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
s8 func_80014D50();
#include "psyq/libsnd.h"
X4_CdlCB func_800648B4(X4_CdlCB func);
extern s32* D_80097750;
extern s32 D_80097758[];

// 0x80015A0C load_vab_record: CD record handler D_80010038[2] (cmd>>16==2): SsVabOpenHeadSticky on the record head, body to SPU.
// basis: oracle assets.tsv:261:vab:2
// callers: none known (reached through the handler table D_80010038)
void load_vab_record(void) {
    u8* p;
    s32* b;
    u8 a;
    s32 n;
    u32 i;

    D_800E01D6++;
    if (D_800E01D6 - D_800E01D4 >= 0x20) {
        func_800648B4(0);
        CdControlB(9, 0, 0);
        D_8009509C = 0x80;
        return;
    }
    a = D_800E01BC;
    i = (D_800E01BC >> 8) & 0xFF;
    D_800E01E8[D_800DF999].transfer_pending = 0;
    if (D_800E01CD != 0) {
        b = D_80097750;
        D_80097758[i] = D_800E0374;
        D_80097778[i] = b + 2;
        p = (u8*)b + (*b & 0xFFFFFF);
        D_80097738[i] = p;
        if ((D_80090D50[i] = SsVabOpenHeadSticky(p, a, D_800E0374)) == -1) {
            func_800648B4(0);
            CdControlB(9, 0, 0);
            D_8009509C = 0x80;
            return;
        }
        SpuSetTransferMode(0);
        n = D_800E01A8;
        D_800E01CD = 0;
        D_800E01E8[D_800DF999].transfer_pending = 0xFFFF;
        D_800E01C8 = n;
        D_800E0374 += n;
    }
    D_800E01AC = D_800CF998.sectors[D_800DF999];
    if (func_80014D50() == -1) {
        func_800648B4(0);
        CdControlB(9, 0, 0);
        D_8009509C = 0x80;
        return;
    }
    D_8008EC08 = 1;
    D_800E01E8[D_800DF999].pending = 1;
    D_800E01E8[D_800DF999].callback = 2;
    D_800E01E8[D_800DF999].callback_arg = i;
    D_800DF999++;
    if (D_800DF999 == 0x20) {
        D_800DF999 = 0;
    }
}
