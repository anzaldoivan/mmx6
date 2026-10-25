#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8003D330();
extern s8 D_80097240;
extern s8 D_800CCF5C;
extern s16 D_800F6AF0;

void func_800F2CDC(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (25/38)
    register s32 a asm("$4");

    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (33/38)
        register s32 t asm("$2") = M2C_FIELD(arg0, u16*, 0x7E) - 1;
        M2C_FIELD(arg0, s16*, 0x7E) = t;
        if ((t << 16) == 0) {
            func_80016C48(0, 0xE, 0);
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
        }
    }
    if ((s8)++M2C_FIELD(arg0, u8*, 0x5C) == D_800CCF5C) {
        a = M2C_FIELD(arg0, u8*, 0x86);
        D_800F6AF0 = 0;
        D_80097240 = a;
        M2C_FIELD(arg0, u8*, 5) = 2;
        M2C_FIELD(arg0, u8*, 6) = 0;
        func_8003D330(a);
    }
}
