#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);

void func_800EA750(u8* arg0) {
    if ((arg0[0x70] & 8) && ((s8)arg0[0x45] == 2)) {
        arg0[5] = 1;
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = 0;
        arg0[0x67] = 0;
        func_800179A4(arg0, 1);
    } else {
        func_8002D230(arg0);
    }
    func_80017A04(arg0);
}
