#include "common.h"

#define M2C_UNK s32

M2C_UNK TestEvent(s32); /* extern */
extern s32 D_800E2F80;
extern s32 D_800E2F84;
extern s32 D_800E2F88;

void func_8001CA64(void) {
    TestEvent(D_800E2F80);
    TestEvent(D_800E2F84);
    TestEvent(D_800E2F88);
}
