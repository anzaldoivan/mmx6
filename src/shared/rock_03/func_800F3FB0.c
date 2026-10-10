#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern struct X4_MainObj* D_800F7DEC;

void func_800F3FB0(void* arg0) {
    register void* p asm("$2");
    u8 f;
    u8 t;

    f = M2C_FIELD(D_800F7DEC, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x15) = f;
    if (f == 0) {
        p = D_800F7DEC;
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(p, s16*, 0xA) + 3;
    } else {
        p = D_800F7DEC;
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(p, s16*, 0xA) - 3;
    }
    {
        register s32 e asm("$4") = M2C_FIELD(p, u16*, 0xE) - 6;
        M2C_FIELD(arg0, s16*, 0xE) = e;
    }
    t = M2C_FIELD(D_800F7DEC, u8*, 0x17);
    if (t == 0 || t == 2 || t == 3 || t == 4) {
        if (M2C_FIELD(arg0, s8*, 0x6) == 0) {
            func_80016C48(2, 0x30, arg0);
            M2C_FIELD(arg0, s8*, 0x6) = 1;
        }
    } else {
        M2C_FIELD(arg0, s8*, 0x6) = 0;
        func_80016C48(2, 0x14, arg0);
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    p = D_800F7DEC;
    if (M2C_FIELD(p, u8*, 0x17) == 0) {
        func_8002CCB0(arg0, 0x40, 0x20);
    }
}
