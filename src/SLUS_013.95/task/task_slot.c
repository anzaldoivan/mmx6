// prog SLUS_013.95 | system task | range 0x800133F4-0x80013448
#include "common.h"
#define M2C_UNK s32
#include "psyq/libapi.h"
#include "mmx6/task.h"

// 0x800133F4 end_task_slot: closes the thread of task slot arg0 and clears its state.
// basis: code code:src/SLUS_013.95/task/task_slot.c:18 via=CloseTh
// callers: none known
// unnamed callers: func_80012EB4, func_8001D0E4
M2C_UNK end_task_slot(M2C_UNK arg0) {
    struct TaskSlot* p;

    p = &g_task_slots[arg0];
    if (p->status != 0) {
        p->status = 0;
        EnterCriticalSection();
        CloseTh(p->thread);
        ExitCriticalSection();
    }
}
