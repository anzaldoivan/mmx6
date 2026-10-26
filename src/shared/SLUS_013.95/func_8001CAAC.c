#include "common.h"

#define M2C_UNK s32

M2C_UNK TestEvent(s32); /* extern */
extern s32 D_800E2F80;
extern s32 D_800E2F84;
extern s32 D_800E2F88;

s32 func_8001CAAC(void) {
    s32 i;

    for (i = 0x3D08F; i != 0; i--) {
        if (TestEvent(D_800E2F80) != 0) {
            return 0;
        }
        if (TestEvent(D_800E2F84) != 0) {
            return 1;
        }
        if (TestEvent(D_800E2F88) != 0) {
            return 2;
        }
    }
    return 3;
}
