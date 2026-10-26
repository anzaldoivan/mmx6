#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#define M2C_UNK s32

void func_80018444(void);
extern u8 D_8008EC08;
extern u8 D_8009509C;
extern u8 D_800DF998;
extern u8 D_800DF999;
extern u8 D_800E01CC;
extern u16 D_800E01D4;
extern u16 D_800E01D6;

void func_800163A4(void) {
    u8 sp10;

    sp10 = 0xA0;
    while (CdInit() == 0) {
    }
    while (CdControl(0xE, &sp10, 0) == 0) {
    }
    VSync(3);
    D_800E01CC = 0;
    D_8009509C = 0;
    D_8008EC08 = 0;
    D_800DF999 = 0;
    D_800DF998 = 0;
    D_800E01D4 = 0;
    D_800E01D6 = 0;
    func_80018444();
}
