#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800FCAEC(void*, M2C_UNK); /* extern */

void func_800FF684(void* arg0) {
    s8 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        temp_v1 = M2C_FIELD(arg0, s8*, 2);
        switch (temp_v1) { /* irregular */
        case 16:
            func_800FCAEC(arg0, 0x10);
            break;
        case 17:
            func_800FCAEC(arg0, 0x11);
            break;
        case 18:
            func_800FCAEC(arg0, 0x12);
            break;
        case 19:
            func_800FCAEC(arg0, 0x13);
            break;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
