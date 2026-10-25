#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80014E60(s32, s32);
u8 func_80016570(void);
int func_80060964(int mode);
s32 func_80064804(s32);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);
extern u8 D_8008EC08;
extern u8 D_8009509C;
extern M2C_UNK* D_800B91B8;
extern s32 D_800E01A8;
extern u8* D_800E01AC;
extern s32 D_800E01B0;
extern s32 D_800E01B4;
extern s32 D_800E01C0;
extern s32 D_800E0374;
extern u8 D_800E0379;
extern s32 D_800E037C;
extern u32 D_800E0380;
extern u8 D_800E0B58[];
extern M2C_UNK* D_800E0D30;
extern s32 D_800E0D34;

s32 func_80014B78(void) {
    u8 sp10;
    s32 off;
    s32 a;
    s32 b;
    s32 s2;
    u8 s1;

    sp10 = 0xA0;
    if ((D_8009509C == 2) && (D_8008EC08 == 0)) {
        D_800B91B8 = D_800E0D30;
        D_800E0374 = D_800E0D34;
        return 1;
    }
    if (D_8009509C & 0xC0) {
        s1 = D_800E0379;
        s2 = D_800E037C;
        D_800E0D30 = D_800B91B8;
        D_800E0D34 = D_800E0374;
        if (func_80064894(1, 0) != 0) {
            func_80064B44(9, 0, 0);
        }
        if (D_8009509C != 0x80) {
            D_800E0380 = 0;
        }
        off = s1 * 8;
        D_8009509C = 0;
        D_800E0379 = s1;
        D_800E037C = s2;
        do {
        } while (func_80016570() & 0x40);
        {
            // !FAKE: depin: dropping it breaks the match (69/118)
            register s32 b asm("$5") = *(s32*)(off + D_800E0B58);
            // !FAKE: depin: dropping it breaks the match (72/118)
            register s32 a asm("$4") = *(s32*)(D_800E0B58 + off + 4);
            D_800E01C0 = 0;
            D_800E01AC = (u8*)s2;
            D_800E01B4 = b;
            D_800E01B0 = a;
            D_800E01A8 = a;
            func_80014E60(a, b);
        }
        return 0;
    }
    if (++D_800E0380 >= 0x259U) {
        func_800648B4(0);
        do {
        } while (func_80064804(0) == 0);
        do {
        } while (func_80064B44(0xE, (s32)&sp10, 0) == 0);
        func_80060964(3);
        D_8009509C = 0xC0;
    }
    return 0;
}
