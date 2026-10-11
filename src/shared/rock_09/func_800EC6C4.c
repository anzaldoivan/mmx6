#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern u8 D_800F4BF0[];
extern struct X4_Unk_unk68 D_800F5F04;

void func_800EC6C4(void* arg0) {
    register s32 tbl asm("$3");
    register s32 v asm("$4");

    func_800179A4(arg0, 3);
    tbl = (s32)(D_800F4BF0 + 0x1324);
    v = *(s32*)((M2C_FIELD(arg0, u8*, 0x15) >> 4 & 4) + tbl);
    {
        register void* a asm("$2") = &D_800F5F04;
        M2C_FIELD(arg0, void**, 0x50) = a;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 1;
    {
        register s32 b asm("$3") = M2C_FIELD(arg0, u8*, 0x6);
        M2C_FIELD(arg0, u8*, 0x6) = b + 1;
    }
    M2C_FIELD(arg0, s32*, 0x20) = v;
}
