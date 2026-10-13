#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800FD4E8[])(void*);

void func_800FACF8(u8* arg0) {
    s8* p;

    p = *(s8**)(arg0 + 0x50);
    if (p[4] != 1 || p[5] == 3) {
        arg0[3] = 0;
        arg0[4]++;
        return;
    }
    func_80017A04(arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
    (*(void (**)(void*))(((s8)arg0[5] << 2) + (s32)D_800FD4E8))(arg0);
}
