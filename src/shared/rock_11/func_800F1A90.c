#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F1A90 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002C458();
extern u32* D_80095098;

#define F(type, off) M2C_FIELD(self, type*, off)
#define G(type, off) M2C_FIELD(obj, type*, off)

M2C_UNK func_800F1A90(void* self, u8 arg1) {
    s32 a;
    s32 b;
    void* obj;
    s32 k;
    register s32 t asm("$4");

    obj = func_8002C458();
    {
        register s32 k2 asm("$2") = 0x41;
        if (obj != 0) {
            register s32 k3 asm("$3") = 0x1C;
            G(u8, 0) = k2;
            G(u8, 1) = k3;
            t = F(u8, 0x15);
            G(void*, 0x7C) = self;
            G(u8, 2) = arg1;
            G(u8, 0x15) = t;
            G(u16, 0xA) = F(u16, 0xA);
            G(u16, 8) = 0;
            G(u16, 0xE) = F(u16, 0xE);
            G(u16, 0xC) = 0;
            G(s32, 0x30) = F(s32, 0x30);
            G(u8, 0x14) = F(u8, 0x14);
            G(u16, 0x40) = F(u16, 0x40) + 0x400;
            G(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1)) + 1] >> 7;
            a = func_8002A47C(F(s8, 1));
            b = func_8002A47C(F(s8, 1));
            a = (a + 1) * 4;
            G(s16, 0x42) = ((a + 0x20) % 16) | (((b + 9) / 4 + 0x1E0) << 6);
            G(u8*, 0x3C) = (u8*)SPAD20_800F1A90 +
                           SPAD20_800F1A90[func_8002A47C(F(s8, 1)) + 1];
        }
    }
}
