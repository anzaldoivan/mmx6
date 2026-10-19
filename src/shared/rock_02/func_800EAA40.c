#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern void (*D_800FAAD4[])(s8*);

#define AA40_SP64 (*(u8**)(0x1F800064))
#define AA40_P(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800EAA40(s8* arg0) {
    if (((s8*)AA40_P(arg0, 0x50))[4] == 2) {
        arg0[3] = 0;
        ((u8*)arg0)[4]++;
        return;
    }
    func_80017A04(arg0);
    D_800FAAD4[arg0[5]](arg0);
    *(s16*)(arg0 + 0xE) =
        *(s16*)(AA40_P(arg0, 0x50) + 0xE) + *(s16*)(AA40_SP64 + 0x56);
}
