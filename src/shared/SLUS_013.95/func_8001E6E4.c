#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern void (*g_playthrough_state_handlers[])(struct X4_EngineObj*);
void task_yield(s32);

void func_8001E6E4(void) {
    while (1) {
        s32 i = g_playthrough_state.state;
        g_playthrough_state_handlers[i](&g_playthrough_state);
        task_yield(1);
    }
}
