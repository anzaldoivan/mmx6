#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80049E50(void*);

void func_801F0E6C(void* arg0) {
    if (func_8002CBFC(arg0, 0x18, 0x18) == 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        func_8002D230(arg0);
        {
            // !FAKE: first flag read lands in the first return register
            register s32 flag asm("$2") = M2C_FIELD(arg0, u8*, 0x70);
            if (flag == 0) {
                func_8002EE10(arg0);
                if (M2C_FIELD(arg0, u8*, 0x70) == 0) {
                    return;
                }
            }
        }
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    } else {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}
