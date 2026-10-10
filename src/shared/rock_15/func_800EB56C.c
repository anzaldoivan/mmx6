#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);

extern M2C_UNK D_800743DC;
extern struct X4_PlayerObj D_800970A0;
extern M2C_UNK D_800F6060;
extern M2C_UNK D_800F6064;
extern M2C_UNK D_800F6068;
extern M2C_UNK D_800F6154;

#define U8(o) M2C_FIELD(self, u8*, o)
#define S8(o) M2C_FIELD(self, s8*, o)
#define U16(o) M2C_FIELD(self, u16*, o)
#define S16(o) M2C_FIELD(self, s16*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PTR(o) M2C_FIELD(self, void**, o)

void func_800EB56C(void* self) {
    struct X4_PlayerObj* p = &D_800970A0;
    s32 x;
    s32 t;

    U8(0x0) = 0x41;
    U8(0x5C) = 0x1E;
    U8(0x61) = 0;
    U8(0x60) = 4;
    t = M2C_FIELD(p, u8*, 0x14);
    {
        register void* a asm("$2") = &D_800743DC;
        PTR(0x58) = a;
    }
    PTR(0x30) = &D_800F6154;
    U8(0x16) = 5;
    x = S32(0x8);
    PTR(0x68) = &D_800F6068;
    PTR(0x54) = &D_800F6060;
    PTR(0x50) = &D_800F6064;
    S32(0x20) = 0;
    S32(0x24) = 0;
    S32(0x28) = 0;
    S32(0x2C) = 0;
    U8(0x67) = 0;
    U8(0x14) = t;
    S32(0x18) = x;
    S32(0x1C) = S32(0xC);
    switch (U8(0x2) >> 4) {
    case 0:
        U8(0x15) = (p->x_pos.val >= x) << 6;
        break;
    case 1:
        U8(0x15) = 0;
        break;
    case 2:
        U8(0x15) = 0x40;
        break;
    }
    func_800179A4(self, 0);
    {
        register s32 v asm("$2") = 2;
        U8(0x5) = v;
        v = U8(0x4);
        U16(0x7C) = 0x28;
        S32(0x80) = 0;
        S32(0x84) = 0;
        S32(0x88) = 0;
        S32(0x8C) = 0;
        S32(0x90) = 0;
        S32(0x94) = 0;
        U8(0x6) = 0;
        U8(0x4) = v + 1;
    }
    if (S8(0x2) == 2) {
        U16(0x7C) = 0xA;
    }
}
