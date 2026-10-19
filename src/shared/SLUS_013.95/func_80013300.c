#include "common.h"
#define M2C_UNK s32
s32 func_80069E74(s32, s32, s32);
M2C_UNK func_80069ED4();
M2C_UNK func_80069EE4();

M2C_UNK func_80013300(M2C_UNK arg0, M2C_UNK* arg1) {
    u8* p;

    func_80069ED4();
    p = (u8*)((arg0 << 7) + 0x801F8100);
    *(s32*)(p + 8) =
        func_80069E74((s32)arg1, *(s32*)(p + 0x10), *(s32*)(p + 0x44));
    func_80069EE4();
    *(u16*)p = 2;
}
