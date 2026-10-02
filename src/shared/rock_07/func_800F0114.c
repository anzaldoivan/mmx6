#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80030ECC();                                 /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);         /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_800F8D84;

void func_800F0114(void* arg0) {
    u8 temp_v0;

    M2C_FIELD(arg0, s8*, 3) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        func_80030ECC();
        if (!(M2C_FIELD(arg0, u8*, 0x85) & 3)) {
            func_80049EBC(arg0, 1, 0x20, 0x20);
        }
        if (!(M2C_FIELD(arg0, u8*, 0x85) & 7)) {
            func_800477E4(3, &D_800F8D84, arg0);
        }
        temp_v0 = M2C_FIELD(arg0, u8*, 0x85);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8*, 0x85) = (u8)(temp_v0 - 1);
            return;
        }
        goto block_7;
    }
block_7:
    func_8002CA14(arg0);
}
