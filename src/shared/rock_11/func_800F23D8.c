#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 func_800533F4(M2C_UNK);
M2C_UNK func_80053440(M2C_UNK);
extern M2C_UNK D_800FD930;
extern M2C_UNK D_800FD9D0;
extern s16 D_800FDA70;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F23D8(void* self) {
    D_800FDA70++;
    func_8002B410(&D_800FD9D0, &D_800FD930, 0x50, D_800FDA70, 0x60);
    func_8002B3D4(0x60, &D_800FD9D0, 5);
    if (D_800FDA70 >= 0x60) {
        if (func_800533F4(1) == 0) {
            func_80021760(1, 0xFF, 0);
            func_80053440(1);
        }
        F(u8, 6)++;
    }
}

#undef F
