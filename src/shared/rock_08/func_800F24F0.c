#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)
#define UH(p, o) M2C_FIELD(p, u16*, o)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
extern s16 D_800F6AF0;

void func_800F24F0(void* arg0) {
    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (29/33)
        register s32 t asm("$2") = H(arg0, 0x7C);
        if (t != 0) {
            H(arg0, 0x7C)--;
            return;
        }
    }
    {
        // !FAKE: depin: dropping it breaks the match (31/33)
        register void* a asm("$4") = arg0;
        if (SB(arg0, 0x89) != 0) {
            SB(arg0, 0x89)--;
            func_800179A4(a, 2);
            {
                // !FAKE: depin: dropping it breaks the match (30/33)
                register s32 c asm("$2") = B(arg0, 0x6) - 1;
                B(arg0, 0x6) = c;
            }
            return;
        }
    }
    D_800F6AF0 = 0;
    B(arg0, 0x5) = 2;
    B(arg0, 0x6) = 0;
}
