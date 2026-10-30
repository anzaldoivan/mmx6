#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(void*, void*);                /* extern */
void init_buster_shot_visual(struct X4_VisualObj*); /* extern */
M2C_UNK func_80049800(void*, void*);                /* extern */
extern s8 D_800970A5;

void func_80049478(void* arg0) {
    if (D_800970A5 == 0x14) {
        clear_object_slot(arg0, arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        ((void (*)())init_buster_shot_visual)(arg0, arg0);
        return;
    }
    func_80049800(arg0, arg0);
}
