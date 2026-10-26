#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

u8 func_80016570(void) {
    u8 sp10;

    do {

    } while (CdControlB(1, 0, &sp10) == 0);
    return sp10;
}
