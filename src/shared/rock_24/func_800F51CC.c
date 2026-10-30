#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();                      /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800F51CC(void* arg0) {
    void* temp_v0;
    s16 v;
    s32 t;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x1A;
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    if ((s16)--M2C_FIELD(arg0, u16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        M2C_FIELD(arg0, u8*, 0x61) -= 5;
        if (M2C_FIELD(arg0, s8*, 0x61) >= 0x1A) {
            M2C_FIELD(arg0, u8*, 0x61) = 0;
        }
        t = M2C_FIELD(arg0, s8*, 0x61);
        if (t >= 6) {
            v = t;
        } else {
            v = 5;
        }
        M2C_FIELD(arg0, u16*, 0x7E) = v;
    }
    func_8002CCB0(arg0, 0x30, 0x40);
}
