#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
M2C_UNK func_800F3E10(void*, M2C_UNK);
extern M2C_UNK D_800FD530;
extern M2C_UNK D_800FD730;
extern M2C_UNK D_800FD930;
extern M2C_UNK D_800FD9D0;
extern s16 D_800FDA70;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F252C(void* self) {
    F(u8, 7) = 0;
    func_800F3E10(self, 2);
    func_800F3E10(self, 0x10);
    func_800F3E10(self, 0x11);
    func_800F3E10(self, 0x12);
    func_800F3E10(self, 0x13);
    func_8002B410(&D_800FD730, &D_800FD530, 0x100, D_800FDA70, 0x60);
    func_8002B3D4(0x3C, &D_800FD730, 0x10);
    func_8002B410(&D_800FD9D0, &D_800FD930, 0x50, D_800FDA70, 0x60);
    func_8002B3D4(0x60, &D_800FD9D0, 5);
    F(s16, 0x7C) = 3;
    F(u8, 6)++;
}

#undef F
