#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8004ACBC(); /* extern */
void func_8004AD78(); /* extern; was M2C_UNK (W15 regate of 4AD78) */

void func_8004AC7C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        func_8004ACBC();
        return;
    }
    func_8004AD78();
}
