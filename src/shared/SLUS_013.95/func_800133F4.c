#include "common.h"
#define M2C_UNK s32
s32 func_80069E84(s32);
M2C_UNK func_80069ED4();
M2C_UNK func_80069EE4();

M2C_UNK func_800133F4(M2C_UNK arg0) {
    u8* p;

    p = (u8*)((arg0 << 7) + 0x801F8100);
    if (*(u16*)p != 0) {
        *(u16*)p = 0;
        func_80069ED4();
        func_80069E84(*(s32*)(p + 8));
        func_80069EE4();
    }
}
