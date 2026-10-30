#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();                      /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800F5564(void* arg0) {
    void* temp_v0;
    s8 temp_v1;
    s8 var_v0;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x1A;
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 5)++;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        if ((M2C_FIELD(arg0, s8*, 0x61) -= 5) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        temp_v1 = M2C_FIELD(arg0, s8*, 0x61);
        var_v0 = temp_v1 < 6;
        if (var_v0 != 0) {
            var_v0 = 5;
        } else {
            var_v0 = temp_v1;
        }
        M2C_FIELD(arg0, s16*, 0x7E) = var_v0;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
}
