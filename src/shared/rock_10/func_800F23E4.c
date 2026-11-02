#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800F23E4(struct ObjectHeader* arg0) {
    if (arg0->state == 4) {
        func_8002CA54();
        return;
    }
    func_8002CA14();
}
