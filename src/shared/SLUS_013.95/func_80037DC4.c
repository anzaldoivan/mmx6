#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*); /* extern */
s32 func_8003A628(void*);     /* extern */
M2C_UNK func_8003CCBC();      /* extern */

void func_80037DC4(void* arg0) {
    func_8003CCBC();
    if (func_8003A628(arg0) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xD0) == 0) {
            M2C_FIELD(arg0, s8*, 5) = 2;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        func_80017A04(arg0);
    }
}
