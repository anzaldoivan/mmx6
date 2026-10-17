#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
extern s32 D_800FBC70;

void func_800F1594(void* arg0) {
    u8 temp_v0;
    void* temp_a0;
    void* temp_v1;

    if (D_800FBC70 != 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
    temp_v0 = M2C_FIELD(temp_v1, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x15) = temp_v0;
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) + 8;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) - 8;
    }
    temp_a0 = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, s16*, 0xE) = (s16)(M2C_FIELD(temp_a0, s16*, 0xE) - 8);
    if ((M2C_FIELD(temp_a0, s8*, 5) != 0xA) ||
        (M2C_FIELD(temp_a0, s8*, 6) >= 4)) {
        func_8002CCB0(arg0, 0x40, 0x40);
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}
