#include "common.h"
#define M2C_UNK s32
s32 CloseTh(s32);
M2C_UNK EnterCriticalSection();
M2C_UNK ExitCriticalSection();

// 0x800133F4 end_task_slot: closes the thread of task slot arg0 and clears its state.
// basis: code src/shared/SLUS_013.95/end_task_slot.c:17 via=CloseTh
// callers: func_80012EB4, func_8001D0E4
M2C_UNK end_task_slot(M2C_UNK arg0) {
    u8* p;

    p = (u8*)((arg0 << 7) + 0x801F8100);
    if (*(u16*)p != 0) {
        *(u16*)p = 0;
        EnterCriticalSection();
        CloseTh(*(s32*)(p + 8));
        ExitCriticalSection();
    }
}
