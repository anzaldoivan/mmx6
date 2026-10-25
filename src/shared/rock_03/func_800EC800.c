#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);

extern M2C_UNK D_800743DC;
extern M2C_UNK D_800F73EC;
extern M2C_UNK D_800F73F4;
extern M2C_UNK D_800F73FC;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EC800(void* arg0) {
    func_8002D230(arg0);
    func_80017A04(arg0);
    if (F(u8, 0x47) == 0x17 || F(u8, 0x47) == 0x10) {
        func_80016C48(2, 9, arg0);
        F(void*, 0x68) = &D_800F73EC;
        F(void*, 0x54) = &D_800F73FC;
        F(void*, 0x50) = &D_800F73F4;
        F(void*, 0x58) = &D_800743DC;
        func_800179A4(arg0, 4);
        {
            // !FAKE: depin: dropping it breaks the match (37/40)
            register s32 v asm("$2") = F(u8, 0x7) + 1;
            F(u8, 0x7) = v;
        }
    }
}

#undef F
