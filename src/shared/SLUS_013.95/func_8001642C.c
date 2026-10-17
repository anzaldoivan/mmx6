#include "common.h"
#define M2C_UNK s32

void func_80014E60(s32, s32);
s32 func_80064894(s32, s32);
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);
extern u8 D_8009509C;
extern s32 D_800E01A8;
extern u8* D_800E01AC;
extern s32 D_800E01B0;
extern s32 D_800E01B4;
extern s32 D_800E01C0;
extern u8 D_800E0379;
extern s32 D_800E037C;
extern u32 D_800E0380;
extern s32 D_800E0398[][2];

void func_8001642C(s32 arg0, s32* arg1, u8* arg2) {
    u8 res[8];
    s32* p;
    // !FAKE: depin: dropping it breaks the match (43/60)
    register s32 a asm("$4");
    // !FAKE: depin: dropping it breaks the match (44/60)
    register s32 b asm("$5");

    if (func_80064894(1, 0) != 0) {
        func_80064B44(9, 0, 0);
    }
    if (D_8009509C != 0x80) {
        D_800E0380 = 0;
    }
    D_8009509C = 0;
    D_800E0379 = arg0;
    D_800E037C = (s32)arg1;
    do {
        while (func_80064B44(1, 0, res) == 0) {
        }
    } while (res[0] & 0x40);
    p = D_800E0398[arg0];
    a = p[1];
    b = p[0];
    D_800E01C0 = 0;
    D_800E01AC = (u8*)arg1;
    D_800E01B0 = a;
    D_800E01B4 = b;
    D_800E01A8 = a;
    func_80014E60(a, b);
}
