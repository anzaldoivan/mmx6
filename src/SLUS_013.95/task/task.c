// prog SLUS_013.95 | system task | range 0x80013300-0x8001335C
#include "common.h"
#define M2C_UNK s32
#include "psyq/libapi.h"
#include "mmx6/task.h"

// 0x80013300 create_task: opens the thread of task slot arg0 with entry arg1 and marks it running.
// basis: code code:src/SLUS_013.95/task/task.c:16 via=OpenTh
// callers: init_system
// unnamed callers: func_800139A0, func_80013A48
M2C_UNK create_task(M2C_UNK arg0, M2C_UNK* arg1) {
    struct TaskSlot* p;

    EnterCriticalSection();
    p = &g_task_slots[arg0];
    p->thread = OpenTh((s32)arg1, p->stack, p->gp);
    ExitCriticalSection();
    p->status = 2;
}
