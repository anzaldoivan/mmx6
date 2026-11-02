#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(void*, void*);                /* extern */
void init_buster_shot_visual(struct X4_VisualObj*); /* extern */
M2C_UNK func_80049800(void*, void*);                /* extern */
extern s8 D_800970A5;

// 0x80049478 update_buster_shot_visual: buster shot visual object update: freed on the stage-exit mode, init on state 0, else its step.
// basis: xref init_buster_shot_visual (docs/leads/derived.tsv:25)
// callers: none known (no jal caller; object type table)
void update_buster_shot_visual(struct ObjectHeader* arg0) {
    if (D_800970A5 == 0x14) {
        clear_object_slot(arg0, arg0);
        return;
    }
    if (arg0->state == 0) {
        ((void (*)())init_buster_shot_visual)(arg0, arg0);
        return;
    }
    func_80049800(arg0, arg0);
}
