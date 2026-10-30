#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_800F6734;
extern void* D_800F70E4;

#define SPAD20_800ED948 (*(s32*)0x1F800020)

void func_800ED948(void* arg0) {
    s32 base;
    s32 idx;
    void* p;
    s32 v;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        p = D_800F70E4;
        M2C_FIELD(arg0, s16*, 0x40) = M2C_FIELD(p, s16*, 0x40) + 0x400;
        v = (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 1) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(D_800F70E4, s8*, 1)) + 9) / 4 + 0x1E0)
             << 6);
        {
            void* q = D_800F70E4;
            M2C_FIELD(arg0, s16*, 0x42) = v;
            idx = func_8002A47C(M2C_FIELD(q, s8*, 1));
        }
        base = SPAD20_800ED948;
        M2C_FIELD(arg0, s32*, 0x3C) = base + M2C_FIELD(idx * 4 + base, s32*, 4);
        set_animation(arg0, 0x11);
        {
            // !FAKE: depin: dropping it breaks the match (63/70)
            register s32* a asm("$2") = &D_800F6734;
            M2C_FIELD(arg0, s32**, 0x50) = a;
        }
        {
            // !FAKE: depin: dropping it breaks the match (63/70)
            register s32 k asm("$2") = 0x1E;
            M2C_FIELD(arg0, s16*, 0x88) = k;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
