#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);

void func_801EEBF4(void* arg0) {
    if (func_8002CBFC(arg0, 0x10, 0x10) == 0) {
        func_80017A04(arg0);
        if (M2C_FIELD(arg0, s8*, 0x98) == 0) {
            move_object(arg0);
            if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
                (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
                func_800383F8(arg0);
                // !FAKE: shared reset block reached from the 0x70 arm
                goto block_6;
            }
            func_8002CCB0(arg0, 0x10, 0x10);
            return;
        }
    }
block_6:
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 4) = 3;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
}
