#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_80031474(void*);
s32 func_800FA664(u8* arg0);
extern s8 D_800970A2;
extern s32 D_800FD44C;

void func_800F8390(void* arg0) {
    s32 temp_v0;
    s8 temp_s1;

    temp_s1 = M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 4);
    if (temp_s1 != 1) {
        M2C_FIELD(arg0, s8*, 4) = 6;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    func_80017A04(arg0);
    (*(void (**)(void*))((M2C_FIELD(arg0, s8*, 5) << 2) + (s32)&D_800FD44C))(
        arg0);
    temp_v0 = func_80031474(arg0);
    if (temp_v0 > 0) {
        if ((D_800970A2 != 0) || (temp_v0 == temp_s1)) {
            M2C_FIELD(arg0, s8*, 0x8A) = temp_s1;
        }
        M2C_FIELD(arg0, s8*, 0x5C) = 0x32;
    }
    if (func_800FA664(arg0) != 0) {
        M2C_FIELD(arg0, s8*, 0x8A) = 1;
    }
}
