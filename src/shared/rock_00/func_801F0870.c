#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_801F0858(void* arg0);

void func_801F0870(void* arg0) {
    // !FAKE: second 0x70 read lands in the second return register
    register s32 t asm("$3");

    if (func_8002CBFC(arg0, 0x30, 0x30) == 0) {
        func_80017A04(arg0);
        move_object(arg0);
        if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
            (((void (*)(void*))func_8002EE10)(arg0),
             ((t = M2C_FIELD(arg0, u8*, 0x70)) != 0))) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 1);
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
            M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        }
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x30);
        return;
    }
    func_801F0858(arg0);
}
