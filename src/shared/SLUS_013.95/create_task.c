#include "common.h"
#define M2C_UNK s32
s32 OpenTh(s32, s32, s32);
M2C_UNK EnterCriticalSection();
M2C_UNK ExitCriticalSection();

// 0x80013300 create_task: opens the thread of task slot arg0 with entry arg1 and marks it running.
// basis: code src/shared/SLUS_013.95/create_task.c:15 via=OpenTh
// callers: func_80012658, func_800139A0, func_80013A48
M2C_UNK create_task(M2C_UNK arg0, M2C_UNK* arg1) {
    u8* p;

    EnterCriticalSection();
    p = (u8*)((arg0 << 7) + 0x801F8100);
    *(s32*)(p + 8) = OpenTh((s32)arg1, *(s32*)(p + 0x10), *(s32*)(p + 0x44));
    ExitCriticalSection();
    *(u16*)p = 2;
}
