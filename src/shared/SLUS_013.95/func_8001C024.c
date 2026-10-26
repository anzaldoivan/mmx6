#include "common.h"

#define M2C_UNK s32

s32 OpenEvent(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK EnableEvent(s32);                            /* extern */
M2C_UNK EnterCriticalSection();                               /* extern */
M2C_UNK ExitCriticalSection();                               /* extern */
extern s32 D_800E2F70;
extern s32 D_800E2F74;
extern s32 D_800E2F78;
extern s32 D_800E2F7C;
extern s32 D_800E2F80;
extern s32 D_800E2F84;
extern s32 D_800E2F88;

void func_8001C024(void) {
    EnterCriticalSection();
    D_800E2F70 = OpenEvent(0xF4000001, 4, 0x2000, 0);
    D_800E2F74 = OpenEvent(0xF4000001, 0x100, 0x2000, 0);
    D_800E2F78 = OpenEvent(0xF4000001, 0x2000, 0x2000, 0);
    D_800E2F7C = OpenEvent(0xF4000001, 0x8000, 0x2000, 0);
    D_800E2F80 = OpenEvent(0xF0000011, 4, 0x2000, 0);
    D_800E2F84 = OpenEvent(0xF0000011, 0x100, 0x2000, 0);
    D_800E2F88 = OpenEvent(0xF0000011, 0x8000, 0x2000, 0);
    ExitCriticalSection();
    EnableEvent(D_800E2F70);
    EnableEvent(D_800E2F74);
    EnableEvent(D_800E2F78);
    EnableEvent(D_800E2F7C);
    EnableEvent(D_800E2F80);
    EnableEvent(D_800E2F84);
    EnableEvent(D_800E2F88);
}
