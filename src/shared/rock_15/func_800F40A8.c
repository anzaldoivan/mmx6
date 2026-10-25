#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
void func_800F3824(struct X4_MainObj*);
extern M2C_UNK D_800F6F44;
extern M2C_UNK D_800F6F54;

void func_800F40A8(void* arg0) {
    func_80017A04();
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 4) {
        func_800F3824(arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800F6F54;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6F44;
        func_800179A4(arg0, 0xB);
        {
            // !FAKE: constant 4 in the first return register
            register s32 x asm("$2") = 4;
            M2C_FIELD(arg0, u8*, 5) = x;
            M2C_FIELD(arg0, u8*, 6) = x;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        M2C_FIELD(arg0, s8*, 7) = -1;
    }
}
