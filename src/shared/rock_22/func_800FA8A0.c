#include "common.h"
#include "mmx6/object.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800FA8A0(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    clear_object_slot();
}
