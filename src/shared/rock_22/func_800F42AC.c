#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(s32);
s32 func_8002D654(s8*, u8*);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);
extern struct X4_PlayerObj D_800970A0;

void func_800F42AC(void* arg0) {
    // !FAKE: separate state store tail in the second return register
    register s32 v asm("$3");

    func_80017A04();
    func_8002D2B0(arg0);
    func_80030ECC(arg0);
    if (func_80031474(arg0) < 0) {
        func_80049E50(arg0);
        v = 2;
        // !FAKE: shared state store block with the 0x70 arm
        goto block_6;
    }
    if (func_8002D654((s8*)arg0, (u8*)&D_800970A0) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x70) != 0 ||
            (func_8002EE10(arg0), M2C_FIELD(arg0, u8*, 0x70) != 0)) {
            func_80049D90(arg0);
            v = 2;
        block_6:
            M2C_FIELD(arg0, u8*, 4) = v;
            return;
        }
        if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
            func_8002CCB0(arg0, 0x10, 0x10);
            return;
        }
    }
    M2C_FIELD(arg0, u8*, 4) = 2;
}
