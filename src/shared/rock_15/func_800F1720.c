#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800F3824(struct X4_MainObj*);
extern s16 D_800970AA;

void func_800F1720(void* arg0) {
    s32 d;
    // !FAKE: shift and quotient share the first return register
    register s32 v asm("$2");
    s32 div40;
    s32 div800;
    s32 n;

    func_80017A04();
    {
        // !FAKE: decremented counter in the first return register
        register s32 c asm("$2") = M2C_FIELD(arg0, u16*, 0x8C) - 1;
        M2C_FIELD(arg0, u16*, 0x8C) = c;
        if ((c << 16) != 0) {
            return;
        }
    }
    {
        ((void (*)(void*, s32))set_animation)(arg0, 8);
        d = D_800970AA - M2C_FIELD(arg0, s16*, 0xA);
        if (d < 0) {
            d = M2C_FIELD(arg0, s16*, 0xA) - D_800970AA;
        }
        n = 0x600000;
        div800 = 800;
        div40 = 40;
        M2C_FIELD(arg0, s32*, 0x2C) = n / div800;
        M2C_FIELD(arg0, s32*, 0x24) = 0x4CCC0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        func_800F3824(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            v = d << 16;
        } else {
            v = -d << 16;
        }
        v = v / div40;
        M2C_FIELD(arg0, s32*, 0x20) = v;
        do {
        } while (0);
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}
