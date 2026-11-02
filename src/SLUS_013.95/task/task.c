#include "common.h"
#define M2C_UNK s32
#include "psyq/libapi.h"
#include "mmx6/task.h"

// 0x80013300 create_task: opens the thread of task slot arg0 with entry arg1 and marks it running.
// basis: code src/shared/SLUS_013.95/create_task.c:15 via=OpenTh
// callers: init_system, func_800139A0, func_80013A48
M2C_UNK create_task(M2C_UNK arg0, M2C_UNK* arg1) {
    struct TaskSlot* p;

    EnterCriticalSection();
    p = (struct TaskSlot*)((arg0 << 7) + 0x801F8100);
    p->thread = OpenTh((s32)arg1, p->stack, p->gp);
    ExitCriticalSection();
    p->status = 2;
}
