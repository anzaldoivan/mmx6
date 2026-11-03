/* addr.h -- fixed addresses the code builds as literals (lui/ori), named once (hand-edited; Phase 2.5 T12.c1).
 * The debt scan's address header (psxd_floor.py `address_header`, default include/addr.h): an address literal
 * belongs here, not in a body. Each is a macro, not a linked symbol: a symbol gives lui/addiu and moves bytes.
 * Users include the header of the type (mmx6/task.h includes this one). */
#ifndef ADDR_H
#define ADDR_H

// The task slot table, 4 struct TaskSlot of 0x80 (create_task, end_task_slot; config/symbols g_task_slots).
#define g_task_slots ((struct TaskSlot*)0x801F8100)
// The running task's slot pointer (task_yield; config/symbols g_cur_task_slot).
#define g_cur_task_slot (*(struct TaskSlot**)0x801F8300)
// The scratchpad word 0x1F80001C, x4.h's SP_SPRITE_FRAMES spelled as one literal (player_spawn_dash_spark).
#define g_sp_sprite_frames (*(s32**)0x1F80001C)
// PsyQ ChangeTh id of the main thread (task_yield); not an address, but address-shaped to the scan.
#define MAIN_THREAD_ID 0xFF000000

#endif /* ADDR_H */
