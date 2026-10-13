#include "common.h"
#define M2C_UNK s32

s32 func_800698F4(s32);
M2C_UNK func_80069E44(s32);
extern s32 D_800E2F80;
extern s32 D_800E2F84;
extern s32 D_800E2F88;

s32 func_8001C718(s32 arg0) {
    s32 tries;
    s32 ret;
    s32 n;

    tries = 10;
    ret = 2;
    func_80069E44(D_800E2F80);
    func_80069E44(D_800E2F84);
    func_80069E44(D_800E2F88);
    do {
        if (func_800698F4(arg0 * 0x10) != 0) {
            n = 0x3D08F;
            while (1) {
                if (func_80069E44(D_800E2F80) != 0) {
                    ret = 0;
                    break;
                }
                if (func_80069E44(D_800E2F84) != 0) {
                    ret = 1;
                    break;
                }
                if (func_80069E44(D_800E2F88) != 0) {
                    ret = 2;
                    break;
                }
                if (--n == 0) {
                    ret = 3;
                    break;
                }
            }
            if (ret == 0) {
                break;
            }
        }
    } while (--tries != 0);
    return ret;
}
