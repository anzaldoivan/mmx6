#include "common.h"

#define M2C_UNK s32

s32 func_80064B44(M2C_UNK, M2C_UNK, u8*); /* extern */

u8 func_80016570(void) {
    u8 sp10;

    do {

    } while (func_80064B44(1, 0, &sp10) == 0);
    return sp10;
}
