#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80040488(M2C_UNK);
void func_800F0434(s8* self, u32 arg1);
extern s8 D_800CCEF4;

void func_800F315C(void* arg0) {
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0xD) {
        func_80016C48(2, 0x39, arg0);
        func_80029478(0x3C, 2, 2);
        func_80012D9C(5);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_800F0434(arg0, 0xA);
        func_80040488(0);
        D_800CCEF4 = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}
