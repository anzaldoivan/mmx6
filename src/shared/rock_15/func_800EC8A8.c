#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800EC8A8(void* arg0) {
    void* temp_v1;

    func_80017A04();
    temp_v1 = M2C_FIELD(arg0, void**, 0x50);
    if ((M2C_FIELD(temp_v1, s8*, 0) == 0) ||
        (M2C_FIELD(temp_v1, s32*, 0x8C) != 0)) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_v1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_v1, u16*, 0xE);
    func_8002CCB0(arg0, 0x30, 0x30);
}
