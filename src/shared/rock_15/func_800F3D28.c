#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04();                        /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */

void func_800F3D28(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x67);
    if (temp_v1 == 1) {
        if (M2C_FIELD(arg0, s8*, 0x45) < 3) {
            func_80017A04();
        }
        goto block_8;
    }
    if (temp_v1 == -1) {
        if (M2C_FIELD(arg0, s8*, 0x45) < 3) {
            func_80017A04(arg0);
        }
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            func_80016C48(2, 0x74, arg0);
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
            return;
        }
        goto block_8;
    }
block_8:
    func_8002D230(arg0);
}
