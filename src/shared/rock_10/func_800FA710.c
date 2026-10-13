#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern void (*D_800FCFE0[])(void*);

void func_800FA710(u8* arg0) {
    s8* p;

    p = *(s8**)(arg0 + 0x50);
    if (p[4] != 1 || p[5] == 9) {
        arg0[3] = 0;
        arg0[4]++;
        return;
    }
    func_80017A04(arg0);
    (*(void (**)(void*))(((s8)arg0[5] << 2) + (s32)D_800FCFE0))(arg0);
}
