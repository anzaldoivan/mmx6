#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */
extern s32 D_800FD5A0;

void func_800F950C(void* arg0) {
    void* temp_s1;

    temp_s1 = M2C_FIELD(arg0, void**, 0x84);
    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        if (M2C_FIELD(temp_s1, s8*, 6) == 7) {
            M2C_FIELD(arg0, s32*, 0x20) = (s32)-D_800FD5A0;
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    } else {
        M2C_FIELD(arg0, s8*, 5) = 5;
        M2C_FIELD(arg0, u8*, 6) = 0U;
    }
}
