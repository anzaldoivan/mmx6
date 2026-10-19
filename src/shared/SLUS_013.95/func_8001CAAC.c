#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80069E44(s32); /* extern */
extern s32 D_800E2F80;
extern s32 D_800E2F84;
extern s32 D_800E2F88;

s32 func_8001CAAC(void) {
    s32 i;

    for (i = 0x3D08F; i != 0; i--) {
        if (func_80069E44(D_800E2F80) != 0) {
            return 0;
        }
        if (func_80069E44(D_800E2F84) != 0) {
            return 1;
        }
        if (func_80069E44(D_800E2F88) != 0) {
            return 2;
        }
    }
    return 3;
}
