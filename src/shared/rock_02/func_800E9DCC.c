#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8002F288();
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80031DA8();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
void func_80032BE8(struct X4_PlayerObj*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800FA980;

void func_800E9DCC(void* arg0) {
    s32 v;

    v = M2C_FIELD(arg0, s8*, 0x5C);
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    if (func_80031474(arg0) < 0) {
        for (v = 4; v >= 0; v--) {
            func_80049EBC(arg0, 1, 0x10, 0x10);
        }
        func_800477E4(3, &D_800FA980, arg0);
        func_80049E50(arg0);
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x5C) != v) {
        M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
    }
    func_80032BE8(arg0);
    func_8003208C(arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        func_8002CCB0(arg0, 0x40, 0x40);
    } else {
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
    func_8002F288(arg0);
    func_80031DA8(arg0);
    func_80031F4C(arg0);
    func_80030ECC(arg0);
}
