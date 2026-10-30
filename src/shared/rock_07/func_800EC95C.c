#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
extern u8 D_800F79D0[];

void func_800EC95C(void* arg0) {
    s8 temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    void* temp_a0 = M2C_FIELD(arg0, void**, 0x80);

    if (temp_v1 == 1) {
        M2C_FIELD(arg0, void**, 0x50) = D_800F79D0 + 0xB60;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(temp_a0, u8*, 7) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    } else if (temp_v1 == 2) {
        play_sound(2, 0x46, arg0);
    }
}
