#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s8 func_80014D50();
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
s32 func_800648D4(M2C_UNK, M2C_UNK, u8*);
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);
extern u8 D_8009509C;
extern s32 D_8009B798;
extern M2C_UNK* D_800B91B8;
extern s32 D_800E01A8;
extern s32 D_800E01D0;
extern u8* D_800E0368;
extern s32 D_800E0374;

void func_800165A4(void) {
    if (D_8009509C != 0) {
        D_800E01D0 += 1;
        if (func_80064894(1, 0) != 1) {
        fail:
            func_800648B4(0);
            func_80064B44(9, 0, 0);
            D_8009509C = 0x80;
        } else if (func_80014D50() == -1) {
            // !FAKE: shared failure block, target places it first
            goto fail;
        } else if (D_800E01A8 == 0) {
            func_800648B4(0);
            D_8009509C = 0;
            do {
            } while (func_800648D4(9, 0, 0) == 0);
            D_8009509C = 2;
            D_800B91B8 = (M2C_UNK*)D_800E0368;
            D_8009B798 = D_800E0374;
        }
    }
}
