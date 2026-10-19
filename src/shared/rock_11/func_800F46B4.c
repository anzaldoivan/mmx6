#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
extern void (*D_800FCBB8[])(void*);
extern s8 D_800FD51D;

void func_800F46B4(void* arg0) {
    if (D_800FD51D != 0) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x4)++;
        return;
    }
    ((void (*)(void*))func_80017A04)(arg0);
    if ((M2C_FIELD(arg0, u8*, 0x2) & 0xF) != 0x30) {
        func_8002CCB0(arg0, 0x30, 0x30);
    } else {
        func_8002CCB0(arg0, 0x30, 0xA0);
    }
    D_800FCBB8[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    func_80030ECC(arg0);
}
