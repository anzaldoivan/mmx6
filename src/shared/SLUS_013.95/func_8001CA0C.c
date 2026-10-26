#include "common.h"

#define M2C_UNK s32

M2C_UNK TestEvent(s32); /* extern */
extern s32 D_800E2F70;
extern s32 D_800E2F74;
extern s32 D_800E2F78;
extern s32 D_800E2F7C;

void func_8001CA0C(void) {
    TestEvent(D_800E2F70);
    TestEvent(D_800E2F74);
    TestEvent(D_800E2F78);
    TestEvent(D_800E2F7C);
}
