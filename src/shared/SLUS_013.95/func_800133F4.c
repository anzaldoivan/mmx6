#include "common.h"
#define M2C_UNK s32
s32 CloseTh(s32);
M2C_UNK EnterCriticalSection();
M2C_UNK ExitCriticalSection();

M2C_UNK func_800133F4(M2C_UNK arg0) {
    u8* p;

    p = (u8*)((arg0 << 7) + 0x801F8100);
    if (*(u16*)p != 0) {
        *(u16*)p = 0;
        EnterCriticalSection();
        CloseTh(*(s32*)(p + 8));
        ExitCriticalSection();
    }
}
