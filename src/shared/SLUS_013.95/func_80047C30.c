#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CAB4();
M2C_UNK apply_object_motion();
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
M2C_UNK func_8002CB50();

void func_80047C30(void* arg0) {
    if (func_8002CAB4() == 0) {
        apply_object_motion(arg0);
        ((void (*)())animate_object)(arg0);
        M2C_FIELD(arg0, s8*, 0x3) ^= 1;
        if (M2C_FIELD(arg0, s8*, 0x3) != 0) {
            func_8002CB50(arg0);
        }
    } else {
        clear_object_slot(arg0);
    }
}
