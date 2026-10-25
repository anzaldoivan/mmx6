#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F1A90(void* self, u8 arg1);
void func_800F3E10(void* arg0, s32 arg1);
extern s8 D_800FD514;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EE034(void* self) {
    s16 t;

    F(u8, 7) = 0;
    t = --F(s16, 0x7C);
    if (t == 0) {
        if (D_800FD514 == 0) {
            F(s16, 0x7C) = 0x5A;
            func_800F3E10(self, 0x29);
            return;
        }
        if (D_800FD514 == 1) {
            F(s16, 0x7C) = 0x2D;
            func_800F3E10(self, 0x2A);
            return;
        }
        if (--F(s16, 0x7E) == -1) {
            F(u8, 7) = 6;
            func_800F3E10(self, 0x25);
            func_800F3E10(self, 0x26);
            func_800F3E10(self, 0x27);
            func_800F3E10(self, 0x28);
            {
                s32 n = F(u8, 6) + 1;
                F(s16, 0x7C) = 0x3C;
                F(u8, 6) = n;
            }
            return;
        }
        F(s16, 0x7C) = 0x5A;
    block_8:
        func_800F3E10(self, 0x29);
        return;
    }
    if (D_800FD514 == 1) {
        if (t == 0x16) {
            func_800F1A90(self, 0);
        }
    } else if (t == 0x1E) {
        func_800F1A90(self, 0);
    }
}

#undef F
