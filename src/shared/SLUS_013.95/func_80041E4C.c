#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
extern s32 D_80075EDC;
extern s32 D_80075EE4;

void func_80041E4C(void* self) {
    M2C_FIELD(self, u8*, 0x3) = 0;
    if (M2C_FIELD(self, s8*, 0x7) == 0) {
        func_800179A4(self, 1);
        M2C_FIELD(self, void**, 0x54) = &D_80075EE4;
        M2C_FIELD(self, void**, 0x50) = &D_80075EDC;
        func_8002CCB0(self, 0x30, 0x30);
        M2C_FIELD(self, u8*, 0x6) += 1;
    }
}
