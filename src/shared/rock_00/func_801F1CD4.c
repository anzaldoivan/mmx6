#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);

void func_801F1CD4(void* arg0) {
    s32 var_s1;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, s8*, 0x8D) = 1;
    }
    if (M2C_FIELD(arg0, s8*, 0x8D) != 0) {
        func_80017A04(arg0);
        move_object(arg0);
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, u8*, 0x70) == 0) {
        func_8002EE10(arg0);
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        var_s1 = 1;
    }
    if (var_s1 != 0) {
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) + 9;
        func_800179A4(arg0, 4);
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    if ((M2C_FIELD(arg0, s8*, 3) == 0) && (M2C_FIELD(arg0, s8*, 0x8C) == 0)) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
#undef func_8002CCB0
#undef func_800179A4
