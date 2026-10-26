#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

extern u8 D_800A21B4;
extern s8 D_800E2E16;
extern s32 D_800E2E18;
extern u8 D_800E2E40;
extern s16 D_800E2E48;

void func_800188BC(void) {
    if (D_800E2E48 & D_800A21B4) {
        do {

        } while (CdControl(9, 0, &D_800E2E40) == 5);
        D_800E2E18 = 3;
        if (D_800E2E40 & 0x10) {
            D_800E2E16 = 1;
        }
    }
}
