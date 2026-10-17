#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
void func_8002D2B0(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);
extern s32 D_80097420;

void func_801EE860(void* arg0) {
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_80017A04(arg0);
        func_8002D2B0(arg0);
        if (!(D_80097420 & 3)) {
            M2C_FIELD(arg0, u8*, 0x64) = (u8)(M2C_FIELD(arg0, u8*, 0x64) + 1);
        }
        if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
            (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0)) ||
            (M2C_FIELD(arg0, s8*, 0x98) != 0)) {
            if (M2C_FIELD(arg0, s8*, 0x98) == 0) {
                func_800383F8(arg0);
            }
            M2C_FIELD(arg0, u8*, 3) = 0;
            M2C_FIELD(arg0, u8*, 4) = 2;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
        }
    } else {
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = 2;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
    }
}
