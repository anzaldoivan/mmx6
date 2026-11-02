#include "common.h"

#define SLOT_PTR (*(struct TaskSlot**)0x801F8300)

#include "psyq/libapi.h"
#include "mmx6/task.h"

// 0x80013360 task_yield: sets the current task's wait count to arg0 and switches back to the main thread.
// basis: code src/shared/SLUS_013.95/task_yield.c:13 via=ChangeTh
// callers: func_800146F4, func_8001D0E4, func_8001E6E4, pump_file_loads
void task_yield(s32 arg0) {
    SLOT_PTR->wait = arg0;
    SLOT_PTR->status = 1;
    ChangeTh(0xFF000000);
}

#undef SLOT_PTR
