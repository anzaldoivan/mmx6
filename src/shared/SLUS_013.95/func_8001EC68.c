#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8001A6CC(M2C_UNK);                    /* extern */
M2C_UNK func_80066150(M2C_UNK);                    /* extern */
M2C_UNK func_800664BC(M2C_UNK*, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_8007119C;
extern M2C_UNK D_800711A4;

void func_8001EC68(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 1) == 0) {
        func_800664BC(&D_8007119C, 0x240, 0);
        func_80066150(0);
        if ((M2C_FIELD(arg0, s8*, 0xC) == 0xB) &&
            (M2C_FIELD(arg0, s8*, 0x38) != 0)) {
            func_8001A6CC(8);
        }
        if (M2C_FIELD(arg0, s8*, 0xC) == 0xC) {
            if (M2C_FIELD(arg0, s8*, 0x38) != 0) {
                func_8001A6CC(9);
            }
        }
        func_800664BC(&D_800711A4, 0x140, 0xB0);
        func_80066150(0);
        M2C_FIELD(arg0, s8*, 1) = (s8)((u8)M2C_FIELD(arg0, s8*, 1) + 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    M2C_FIELD(arg0, s8*, 0) = 8;
    M2C_FIELD(arg0, s8*, 1) = 0;
}
