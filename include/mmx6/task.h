// prog SLUS_013.95 | system task | range -
/* mmx6/task.h -- the task slot, one PsyQ thread record of the table at 0x801F8100 (4 x 0x80 bytes; the current slot
 * pointer at 0x801F8300) (hand-edited; Phase 2.5 T9.c1). Names from our readers: create_task, end_task_slot,
 * task_yield, func_800131AC, the slot init in 80012A34.c; thread/stack/gp are OpenTh's result and its sp and gp
 * arguments (PsyQ libapi: `long OpenTh(long (*func)(), unsigned long sp, unsigned long gp)`). */
#ifndef MMX6_TASK_H
#define MMX6_TASK_H

#include "common.h"

struct TaskSlot {
    u16 status; // +0x00 0 free, 1 waiting (task_yield), 2 running (create_task); bit 0x40 set by func_80013480
    s16 wait; // +0x02 frames to wait, set by task_yield, counted down by func_800131AC
    s8 pad04[0x08 - 0x04]; // +0x04 unreferenced
    s32 thread; // +0x08 OpenTh result (create_task), CloseTh argument (end_task_slot)
    s32 tcb; // +0x0C this thread's TCB: the slot init in 80012A34.c stores BIOS ToT TCB base (*0x110) + 0xC0 per slot
    s32 stack; // +0x10 OpenTh sp argument; 0x801FEC00 + 0x400 per slot (the slot init)
    s8 pad14[0x44 - 0x14]; // +0x14 unreferenced here
    s32 gp; // +0x44 OpenTh gp argument
    s8 pad48[0x80 - 0x48]; // +0x48 unreferenced here
};

#endif /* MMX6_TASK_H */
