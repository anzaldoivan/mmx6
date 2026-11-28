#include "common.h"
#include "psyq/libapi.h"
#include "addr.h"
extern s32 D_8006D9AC;
extern s32 D_800CF960;

void func_8001344C(s32 arg0) {
    D_8006D9AC = 1;
    D_800CF960 = arg0;
    ChangeTh(MAIN_THREAD_ID);
}
