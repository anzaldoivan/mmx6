#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*); /* extern */
extern s32 D_800E2E18;
extern M2C_UNK D_800E2E64;

void func_80018B10(void) {
    if ((func_80064874(1, 0) == 2) && (CdControl(0xD, &D_800E2E64, 0) != 0)) {
        D_800E2E18 = 5;
    }
}
