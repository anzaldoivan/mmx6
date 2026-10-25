#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EC53C (*(s32**)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
struct X4_VisualObj* func_8002C398(void);
extern u32* D_80095098;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCEF6;
extern s32 D_800ED7D0;
extern s32 D_800ED7DC;

#define F(type, off) M2C_FIELD(self, type*, off)
#define G(type, off) M2C_FIELD(obj, type*, off)
#define SLOT(i) (D_800CCED0.character_state.bytes[(i) + 6])

void func_800EC53C(void* self) {
    s32 a;
    s32 b;
    s32 i;
    s32 n;
    s8 t;
    s32 one;
    s32 k;
    s8 v;
    void* obj;

    F(u8, 0) = 0x41;
    F(u8, 0x16) = 4;
    F(u16, 0x40) = D_80095098[func_8002A47C(0x94)] >> 7;
    F(u8*, 0x3C) = (u8*)SPAD20_800EC53C + SPAD20_800EC53C[func_8002A47C(0x94)];
    a = func_8002A47C(0x94);
    b = func_8002A47C(0x94);
    a = a * 4;
    F(s16, 0x42) = ((a + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    F(void*, 0x30) = &D_800ED7D0;
    t = F(s8, 2);
    F(void*, 0x68) = &D_800ED7DC;
    F(u8, 0x75) = 0;
    if (t == 10) {
        i = 8;
        n = 0;
        for (; i < 16; i++) {
            if ((&D_800CCEF6)[i] != 0) {
                n++;
            }
        }
        if (n < 8) {
            F(u8, 4) = 2;
            return;
        }
        F(u8, 4) = 1;
        F(u8, 5) = 0;
        F(u8, 2) &= 0xF;
        func_800179A4(self, 0);
        k = 1;
        obj = func_8002C398();
        if (obj != 0) {
            G(u8, 0) = 0x51;
            G(u8, 1) = 0x18;
            G(u8, 2) = k;
            G(u8, 0x16) = k;
            G(u8, 0x15) = 0;
            G(u8, 0x14) = F(u8, 0x14);
            G(u16, 0xA) = F(u16, 0xA);
            G(u16, 0xE) = F(u16, 0xE) - 0x1C;
            G(u16, 0x42) = F(u16, 0x42);
            G(u16, 0x40) = F(u16, 0x40);
            G(s32, 0x3C) = F(s32, 0x3C);
            G(void*, 0x30) = F(void*, 0x30);
            G(void*, 0x50) = self;
        }
        return;
    }
    one = 1;
    v = SLOT(t);
    switch (v) {
    case 0:
        F(u8, 2) &= 0xF;
        F(u8, 5) = 0;
        func_800179A4(self, 0);
        obj = func_8002C398();
        if (obj != 0) {
            G(u8, 0) = 0x51;
            G(u8, 1) = 0x18;
            G(u8, 2) = 0;
            G(u8, 0x16) = one;
            G(u8, 0x15) = 0;
            G(u8, 0x14) = F(u8, 0x14);
            G(u16, 0xA) = F(u16, 0xA);
            G(u16, 0xE) = F(u16, 0xE) - 0x1C;
            G(u16, 0x42) = F(u16, 0x42);
            G(u16, 0x40) = F(u16, 0x40);
            G(s32, 0x3C) = F(s32, 0x3C);
            G(void*, 0x30) = F(void*, 0x30);
            G(void*, 0x50) = self;
        }
        break;
    case 1:
        F(u8, 2) &= 0xF;
        F(s8, 5) = v;
        func_800179A4(self, 0);
        {
            // !FAKE: depin: dropping it breaks the match (198/201)
            register s32 x asm("$2") = F(s8, 2);
            s32 two = 2;
            SLOT(x) = two;
        }
        break;
    case 2:
    default:
        F(u8, 5) = 2;
        F(u8, 2) &= 0xF;
        func_800179A4(self, 0);
        break;
    }
    F(u8, 6) = 0;
    F(u8, 7) = 0;
    F(u8, 4)++;
}
