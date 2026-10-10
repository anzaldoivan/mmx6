#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_8007555C;
extern void (*D_800F96F4[])(void*);

void func_800F2EE4(void* arg0) {
    s32 r;
    u16 t;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 4) != 1) {
        M2C_FIELD(arg0, u8*, 4) = 4;
        M2C_FIELD(arg0, u8*, 3) = 0;
        return;
    }
    func_80017A04(arg0);
    {
        register void** tbl asm("$2") = (void**)D_800F96F4;
        register s32 i asm("$3") = M2C_FIELD(arg0, s8*, 5);
        register void* fp asm("$5") = tbl[i];
        ((void (*)(void*))fp)(arg0);
    }
    r = func_80031474(arg0);
    if (r < 0) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4) = 4;
        M2C_FIELD(arg0, u8*, 5) = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if ((u32)(r - 0x19) < 2) {
            M2C_FIELD(arg0, s16*, 0x84) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x84) = 0x1E;
        }
    }
    t = M2C_FIELD(arg0, u16*, 0x84);
    if (M2C_FIELD(arg0, s16*, 0x84) != 0) {
        M2C_FIELD(arg0, s16*, 0x84) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007555C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}
