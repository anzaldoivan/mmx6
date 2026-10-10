#include "common.h"
#include "mmx6/x4.h"

extern u16 D_800C4570;
extern s8 D_800CCEF8;
extern u16 D_800F36CC;
extern u16 D_800F48EC;
extern s16 D_800F48EE;
extern s16 D_800F48F0;

void func_800EA11C(u8* self) {
    extern u8 D_800CCED0[];
    s8* e;
    s32 t;

    if (D_800C4570 & 0x8FF) {
        D_800CCEF8 = D_800F48F0;
        self[2]++;
        return;
    }
    t = D_800F48EC - 1;
    D_800F48EC = t;
    if ((t << 16) == 0) {
        e = (s8*)D_800CCED0;
        if (++e[0x28] >= D_800F48F0) {
            self[2]++;
            e[0x28] = D_800F48F0;
            return;
        }
        {
            register u16* tbl asm("$3") = &D_800F36CC;
            register s32 v asm("$5");
            s32 i = (u16)D_800F48EE;
            i++;
            D_800F48EE = i;
            v = tbl[(s16)i];
            D_800F48EC = v;
        }
    }
}
