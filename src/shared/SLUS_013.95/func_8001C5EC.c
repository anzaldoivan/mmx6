#include "common.h"
#include "psyq/libcard.h"
#define M2C_UNK s32

s32 func_8001C718(s32 arg0);
s32 func_8001C824(void);
M2C_UNK TestEvent(s32);
extern u8 D_8006D620;
extern s32 D_800E2F70;
extern s32 D_800E2F74;
extern s32 D_800E2F78;
extern s32 D_800E2F7C;

s32 func_8001C5EC(s32 arg0) {
    s32 ret;
    s32 tries;
    s32 prev;

    TestEvent(D_800E2F70);
    tries = 3;
    TestEvent(D_800E2F74);
    prev = 0xFF;
    TestEvent(D_800E2F78);
    TestEvent(D_800E2F7C);
    do {
        if (_card_info(arg0 * 0x10) != 0) {
            ret = func_8001C824();
            if (!(ret & 1) && ret == prev) {
                break;
            }
            prev = ret;
        }
    } while (--tries != 0);
    if (ret == 2) {
        D_8006D620 = 0;
        func_8001C718(arg0);
        ret = 0;
    }
    return ret;
}
