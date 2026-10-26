#include "common.h"
#define M2C_UNK s32
s32 OpenTh(s32, s32, s32);
M2C_UNK EnterCriticalSection();
M2C_UNK ExitCriticalSection();

M2C_UNK func_80013300(M2C_UNK arg0, M2C_UNK* arg1) {
    u8* p;

    EnterCriticalSection();
    p = (u8*)((arg0 << 7) + 0x801F8100);
    *(s32*)(p + 8) =
        OpenTh((s32)arg1, *(s32*)(p + 0x10), *(s32*)(p + 0x44));
    ExitCriticalSection();
    *(u16*)p = 2;
}
