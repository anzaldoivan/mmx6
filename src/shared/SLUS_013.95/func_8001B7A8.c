#include "common.h"

#define M2C_UNK s32

#include "mmx6/x4.h"

void func_8001B5FC(void);
int func_80060964(int mode);
void func_800622A4(void);
s32 func_80064804(s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
s32 func_800648D4(M2C_UNK, M2C_UNK, u8*);
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);
void func_80064DD4(s32);
void func_80068EB4(s32);
void func_80069150(s32);

void func_8001B7A8(void) {
    u8 sp10;

    sp10 = 0x80;
    func_8001B5FC();
    func_80068EB4(0);
    do {

    } while (func_80064B44(9, 0, 0) == 0);
    func_80060964(0);
    func_80064DD4(0);
    func_800648B4(0);
    func_80069150(0);
    func_800622A4();
    do {

    } while (func_80064804(0) == 0);
    func_80060964(3);
    do {

    } while (func_800648D4(0xE, (s32)&sp10, 0) == 0);
    func_80060964(3);
}
