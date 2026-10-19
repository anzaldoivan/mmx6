#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
extern s32 D_80076108;

void func_80044094(void* arg0) {
    void* temp_a0;

    ((void (*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        temp_a0 = M2C_FIELD(arg0, void**, 0x7C);
        if (M2C_FIELD(temp_a0, s16*, 0x94) == 0x1000) {
            M2C_FIELD(temp_a0, s16*, 0x94) = 0;
        }
        func_800179A4(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x98) = 0;
        M2C_FIELD(arg0, s32**, 0x50) = &D_80076108;
        M2C_FIELD(arg0, s16*, 0x8A) = 0;
        M2C_FIELD(arg0, u8*, 0x64) = 1;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
