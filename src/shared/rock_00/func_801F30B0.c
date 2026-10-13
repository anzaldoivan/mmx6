#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_800179D0(void*, M2C_UNK, s8);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8002D2B0(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);
void* func_8003D480(M2C_UNK, s8, s8, void*);
extern s32 D_80097420;

void func_801F30B0(void* arg0) {
    s8 temp_v1;

    if (func_8002CBFC(arg0, 0x20, 0x14) == 0) {
        temp_v1 = M2C_FIELD(arg0, s8*, 0x98);
        if (temp_v1 == 0) {
            func_80017A04(arg0);
            func_8002D2B0(arg0);
            func_8002CCB0(arg0, 0x20, 0x14);
            {
                register s32 f asm("$2") = M2C_FIELD(arg0, u8*, 0x70);
                if ((f != 0) ||
                    (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
                    func_800383F8(arg0);
                    M2C_FIELD(arg0, u8*, 4) = 2;
                    M2C_FIELD(arg0, s32*, 0x50) = 0;
                    M2C_FIELD(arg0, s32*, 0x68) = 0;
                    func_800179D0(arg0, 1, M2C_FIELD(arg0, s8*, 0x45));
                }
            }
            goto block_9;
        }
        if (temp_v1 != -1) {
            if (M2C_FIELD(arg0, s8*, 7) == 1) {
                func_8003D480(0x21, 0x15, 1, arg0);
                goto block_12;
            }
            goto block_9;
        }
        M2C_FIELD(arg0, u8*, 4) = 2;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        func_800179D0(arg0, 1, M2C_FIELD(arg0, s8*, 0x45));
    block_9:
        if (!(D_80097420 & 3)) {
            M2C_FIELD(arg0, u8*, 0x64) = (u8)(M2C_FIELD(arg0, u8*, 0x64) + 1);
        }
        M2C_FIELD(arg0, u8*, 0x98) = 0;
        return;
    }
block_12:
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 4) = 3;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
}
