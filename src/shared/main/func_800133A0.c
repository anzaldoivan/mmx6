#include "common.h"
#include "psyq/libapi.h"
#include "mmx6/task.h"

void func_800133A0(void) {
    g_cur_task_slot->status = 0;
    EnterCriticalSection();
    CloseTh(g_cur_task_slot->thread);
    ExitCriticalSection();
    ChangeTh(MAIN_THREAD_ID);
}
