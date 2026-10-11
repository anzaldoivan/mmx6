#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CD6C(void*);

extern M2C_UNK D_800970A0;
extern s8 D_800CCEF6;
extern void (*D_800F3A50[])(void*);

void func_800F2414(void* self) {
    {
        void* pl = &D_800970A0;
        if (M2C_FIELD(pl, s8*, 0xD0) == 0) {
            M2C_FIELD(self, u16*, 0x88) = M2C_FIELD(pl, u16*, 0x7C);
            M2C_FIELD(self, u16*, 0x8A) = M2C_FIELD(pl, u16*, 0x80);
        } else {
            M2C_FIELD(self, u16*, 0x88) = 0;
            M2C_FIELD(self, u16*, 0x8A) = 0;
        }
    }
    {
        void* pl = &D_800970A0;
        if (M2C_FIELD(pl, s8*, 0xCC) != 0) {
            func_8002CD6C(self);
            return;
        }
    }
    M2C_FIELD(self, s32*, 0x18) = M2C_FIELD(self, s32*, 0x8);
    M2C_FIELD(self, s32*, 0x1C) = M2C_FIELD(self, s32*, 0xC);
    M2C_FIELD(self, u8*, 0xA8) =
        M2C_FIELD(self, u8*, 0x70) | M2C_FIELD(self, u8*, 0x71);
    M2C_FIELD(self, u8*, 0x71) = 0;
    D_800F3A50[M2C_FIELD(self, s8*, 0x4)](self);
    M2C_FIELD(self, u8*, 0x5C) &= 0x7F;
    if ((M2C_FIELD(self, u8*, 0xA8) & 0xC) == 0xC) {
        D_800CCEF6 = 1;
    } else {
        D_800CCEF6 = 0;
    }
}
