#include "common.h"
#include "psyq/libcard.h"
#define M2C_UNK s32

M2C_UNK TestEvent(s32);
extern s32 D_800E2F80;
extern s32 D_800E2F84;
extern s32 D_800E2F88;

s32 func_8001C718(s32 arg0) {
    s32 tries;
    s32 ret;
    s32 n;

    tries = 10;
    ret = 2;
    TestEvent(D_800E2F80);
    TestEvent(D_800E2F84);
    TestEvent(D_800E2F88);
    do {
        if (_card_clear(arg0 * 0x10) != 0) {
            n = 0x3D08F;
            while (1) {
                if (TestEvent(D_800E2F80) != 0) {
                    ret = 0;
                    break;
                }
                if (TestEvent(D_800E2F84) != 0) {
                    ret = 1;
                    break;
                }
                if (TestEvent(D_800E2F88) != 0) {
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
