/* Adapted from sozud/mmx4 @6a6b455 src/main/55C4.c:func_80016E84, AGPL-3.0; proven shared with X6 by exact signature adc4ba01bdcd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
int func_80060964(int mode);
extern u8 D_800E2E40;
#define D_800E2E40 (*(u8(*)[]) & D_800E2E40)
extern s8 D_800E2E16;
extern s32 D_800E2E18;

#define M2C_UNK s32
s8 func_80064874(M2C_UNK, u8*);
s32 func_800648D4(M2C_UNK, M2C_UNK, u8*);
void func_80018B60(void) {

    u8 sp10;

    if (func_80064874(1, 0) == 0x02) {
        sp10 = 0x80 | 0x40 | 0x08;
        if (func_800648D4(0x0e, &sp10, &D_800E2E40) != 0) {
            func_80060964(3);
            D_800E2E18 = 6;
            if (D_800E2E40[0] & 0x10) {
                D_800E2E16 = 1;
            }
        }
    }
}
#undef D_800E2E40
