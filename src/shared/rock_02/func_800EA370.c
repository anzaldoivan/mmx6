#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern void (*D_800FAA70[])(void*);

void func_800EA370(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    func_80017A04();
    D_800FAA70[M2C_FIELD(arg0, s8*, 5)](arg0);
    check_enemy_hits(arg0);
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x50, 0xA0) == 0) {
        func_8002CCB0(arg0, 0x30, 0x40);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = 2;
}
