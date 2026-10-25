#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
void func_800F6F44(void* arg0, s32 arg1);
extern M2C_UNK D_80074E7C;

void func_800F850C(void* arg0) {
    s8 st = M2C_FIELD(arg0, s8*, 0x45);

    if (st == 2) {
        if (func_8002D2D4() & 1) {
            func_80016C48(2, 0x22, arg0);
        } else {
            func_80016C48(2, 0x23, arg0);
        }
        func_80016C48(2, 0x53, arg0);
        func_800F6F44(arg0, 1);
        M2C_FIELD(arg0, void**, 0x58) = &D_80074E7C;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
    } else if (st == 1) {
        func_800179A4(arg0, 0xA);
        {
            // !FAKE: depin: dropping it breaks the match (42/45)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}
