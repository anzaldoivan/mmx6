#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002C9B0();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_80051FE8(void* arg0, void* arg1);
extern s8 D_80097182;
#define D_80097182 (*(u8*)&D_80097182)

void func_800516E0(s8* arg0) {
    s8* temp_a1;

    temp_a1 = *(s8**)(arg0 + 0x50);
    if (*temp_a1 == 0) {
        func_8002C9B0(arg0, temp_a1);
        return;
    }
    if (arg0[4] == 0) {
        func_80051FE8(arg0, temp_a1);
    } else if (D_80097182 == 1) {
        func_8002C9B0(arg0, temp_a1);
        return;
    } else {
        ((M2C_UNK(*)())func_80017A04)(arg0, temp_a1);
    }
    func_8002CCB0((struct X4_BaseObj*)arg0, 0x88, 0x88);
}
#undef D_80097182
