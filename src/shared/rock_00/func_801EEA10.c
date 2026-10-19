#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
void func_801ED36C(s8* arg0);
void func_801EEA8C(void* arg0);

void func_801EEA10(void* arg0) {
    if (func_8002CBFC((struct X4_BaseObj*)arg0, 0x2A, 0x22) == 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, s8*, 1) == 0x14) {
            func_801ED36C(arg0);
            return;
        }
        func_801EEA8C(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 4) = 3;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
}
