#include "common.h"
#include "mmx6/object.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(M2C_UNK*);
extern void (*D_800F7D54[])(void*);

// 0x800F5664 step_commander_yammark: clears byte 3, runs the Commander Yammark state table, then the shared object step.
// basis: xref update_commander_yammark (docs/leads/derived.tsv:32)
// callers: update_commander_yammark
void step_commander_yammark(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    D_800F7D54[arg0->state](arg0);
    func_8002F288(arg0);
}
