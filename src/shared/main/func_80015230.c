#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_800646E4(s32, u8*);
s32 func_80064894(s32, s32);
extern u8 D_800E01D8;

void func_80015230(void) {
    u8 sp10[8];
    u8 sp18[8];

    sp18[0] = 0xA0;
    D_800E01D0 = 0;
    func_800646E4(D_800E01B4, &D_800E01D8);
    do {
        do {
            do {
                while (CdControlB(1, 0, sp10) == 0) {
                }
            } while (sp10[0] & 0x40);
            while (func_80064894(1, 0) != 0) {
            }
        } while (CdControl(0xE, sp18, 0) == 0);
        VSync(3);
    } while (CdControl(2, &D_800E01D8, 0) == 0);
    while (CdControl(6, 0, 0) == 0) {
    }
    D_8009509C = 1;
}
