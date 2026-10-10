#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F5EE8 (*(s32**)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();

#define F(type, off) M2C_FIELD(self, type*, off)
#define G(type, off) M2C_FIELD(obj, type*, off)

void func_800F5EE8(void* self) {
    s8 kind;
    void* obj;

    ((M2C_UNK(*)())func_80017A04)();
    kind = F(s8, 0x45);
    if (kind == 1) {
        func_80016C48(2, 0x1E, self);
        obj = func_8002C458();
        if (obj != 0) {
            G(u8, 0x0) = 0x41;
            G(u8, 0x1) = 0x15;
            G(u8, 0x2) = kind;
            G(s32, 0x8) = F(s32, 0x8);
            G(s32, 0xC) = F(s32, 0xC);
            G(s16, 0x42) = F(u16, 0x42) & 0x7FFF;
            G(s32, 0x30) = F(s32, 0x30);
            G(u8*, 0x3C) =
                (u8*)SPAD20_800F5EE8 + SPAD20_800F5EE8[func_8002A47C(0x37) + 1];
            {
                s32 t = F(u16, 0x40);
                G(void*, 0x7C) = self;
                G(u16, 0x40) = t;
            }
        }
        F(u8, 0x7) = 0;
        F(s16, 0x7C) = 0;
        F(u8, 0x6)++;
    }
}

#undef F
#undef G
#undef SPAD20_800F5EE8
