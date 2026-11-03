// prog SLUS_013.95 | system task | range 0x80013360-0x8001339C
#include "common.h"

#include "psyq/libapi.h"
#include "mmx6/task.h"

// 0x80013360 task_yield: sets the current task's wait count to arg0 and switches back to the main thread.
// basis: code code:src/SLUS_013.95/task/task_yield.c:14 via=ChangeTh
// callers: pump_file_loads
// unnamed callers: func_800146F4, func_8001D0E4, func_8001E6E4
void task_yield(s32 arg0) {
    g_cur_task_slot->wait = arg0;
    g_cur_task_slot->status = 1;
    ChangeTh(MAIN_THREAD_ID);
}
