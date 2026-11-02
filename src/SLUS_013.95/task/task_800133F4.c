#include "common.h"
#define M2C_UNK s32
#include "psyq/libapi.h"
#include "mmx6/task.h"

// 0x800133F4 end_task_slot: closes the thread of task slot arg0 and clears its state.
// basis: code src/shared/SLUS_013.95/end_task_slot.c:17 via=CloseTh
// callers: func_80012EB4, func_8001D0E4
M2C_UNK end_task_slot(M2C_UNK arg0) {
    struct TaskSlot* p;

    p = (struct TaskSlot*)((arg0 << 7) + 0x801F8100);
    if (p->status != 0) {
        p->status = 0;
        EnterCriticalSection();
        CloseTh(p->thread);
        ExitCriticalSection();
    }
}
