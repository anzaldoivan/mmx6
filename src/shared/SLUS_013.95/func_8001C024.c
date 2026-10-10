#include "common.h"

#define M2C_UNK s32

s32 func_80069E14(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80069E54(s32);                            /* extern */
M2C_UNK func_80069ED4();                               /* extern */
M2C_UNK func_80069EE4();                               /* extern */
extern s32 D_800E2F70;
extern s32 D_800E2F74;
extern s32 D_800E2F78;
extern s32 D_800E2F7C;
extern s32 D_800E2F80;
extern s32 D_800E2F84;
extern s32 D_800E2F88;

void func_8001C024(void) {
    func_80069ED4();
    D_800E2F70 = func_80069E14(0xF4000001, 4, 0x2000, 0);
    D_800E2F74 = func_80069E14(0xF4000001, 0x100, 0x2000, 0);
    D_800E2F78 = func_80069E14(0xF4000001, 0x2000, 0x2000, 0);
    D_800E2F7C = func_80069E14(0xF4000001, 0x8000, 0x2000, 0);
    D_800E2F80 = func_80069E14(0xF0000011, 4, 0x2000, 0);
    D_800E2F84 = func_80069E14(0xF0000011, 0x100, 0x2000, 0);
    D_800E2F88 = func_80069E14(0xF0000011, 0x8000, 0x2000, 0);
    func_80069EE4();
    func_80069E54(D_800E2F70);
    func_80069E54(D_800E2F74);
    func_80069E54(D_800E2F78);
    func_80069E54(D_800E2F7C);
    func_80069E54(D_800E2F80);
    func_80069E54(D_800E2F84);
    func_80069E54(D_800E2F88);
}
