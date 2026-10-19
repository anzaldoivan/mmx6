#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
extern M2C_UNK D_800970A0;

void func_801F09C0(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        void* pl;

        if (M2C_FIELD(arg0, s8*, 7) != 0) {
            return;
        }
        pl = &D_800970A0;
        M2C_FIELD(pl, u8*, 0x98) -= 1;
        M2C_FIELD(pl, u8*, 0x99) -= 1;
    } else {
        void* p = M2C_FIELD(arg0, void**, 0x7C);

        if (M2C_FIELD(p, s8*, 7) != 0) {
            M2C_FIELD(p, u8*, 7) -= 1;
        }
    }
    ((M2C_UNK(*)())func_8002C9B0)(arg0, arg0);
}
