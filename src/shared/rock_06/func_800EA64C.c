#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800EA64C(void* arg0) {
    s8 temp_v0;
    void* temp_v1;

    temp_v1 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, u8*, 0x15) = (u8)M2C_FIELD(temp_v1, u8*, 0x15);
    temp_v0 = M2C_FIELD(temp_v1, s8*, 4);
    if (temp_v0 != 2) {
        if (M2C_FIELD(arg0, s8*, 0x46) >= 0) {
            M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_v1, u16*, 0xA);
            M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_v1, u16*, 0xE);
            func_80017A04(arg0);
        } else {
            M2C_FIELD(arg0, s8*, 4) = 2;
        }
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = temp_v0;
}
