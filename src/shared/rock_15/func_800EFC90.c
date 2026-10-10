#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EFC90 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj D_800970A0;
extern s8 D_800CCF01;
extern M2C_UNK D_800F67C0;
extern M2C_UNK D_800F67C8;
extern M2C_UNK D_800F6884;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EFC90(void* self) {
    s32 n;
    s32 m;
    void* obj;
    register u8 c asm("$5");
    u16 x;
    struct X4_PlayerObj* pl;
    register s32 two asm("$18");

    {
        s32 k;
        {
            s8* q = &D_800CCF01;
            two = 2;
            *q = two;
        }
        k = 0x10;
        do {
            F(s8, 0x60) = k;
        } while (0);
    }
    {
        register void* a asm("$2") = &D_8007433C;
        F(void*, 0x58) = a;
    }
    pl = &D_800970A0;
    F(s8, 0x5C) = 0;
    F(s8, 0x61) = 0;
    F(s8, 3) = 0;
    c = pl->bg_offset;
    F(void*, 0x30) = &D_800F6884;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(s8, 0x67) = 0;
    F(u8, 0x16) = 6;
    F(void*, 0x50) = 0;
    F(void*, 0x54) = 0;
    F(s32, 0x68) = 0;
    F(u8, 0x14) = c;
    if (!(F(s8, 2) & 0xF0)) {
        F(u16, 0x40) = 0x140;
        n = func_8002A47C(F(s8, 1));
        m = func_8002A47C(F(s8, 1));
        F(s16, 0x42) = ((n * 4 + 0x20) % 16) | (((m + 8) / 4 + 0x1E0) << 6);
        F(s32, 0x3C) = SPAD20_800EFC90 +
                       *(s32*)(func_8002A47C(F(s8, 1)) * 4 + SPAD20_800EFC90);
        F(s8, 4) = 1;
        F(u16, 0xE) = 0x130;
        F(u16, 0xA) = 0xE90;
        F(s32, 0x68) = 0;
        F(u8, 0x15) = 0;
        F(s8, 5) = two;
        F(void*, 0x50) = &D_800F67C0;
        F(void*, 0x54) = &D_800F67C8;
        func_8003D308(0x14, pl->unk15);
        func_800179A4(self, 0);
    }
    obj = func_8002C458();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0x21;
        M2C_FIELD(obj, u8*, 2) = 0xD;
        M2C_FIELD(obj, s32*, 0x30) = F(s32, 0x30);
        M2C_FIELD(obj, s32*, 0x3C) = F(s32, 0x3C);
        M2C_FIELD(obj, u16*, 0x40) = F(u16, 0x40);
        M2C_FIELD(obj, u8*, 0x15) = F(u8, 0x15);
        M2C_FIELD(obj, u8*, 0x14) = D_800970A0.bg_offset;
        x = F(u16, 0xA);
        M2C_FIELD(obj, u16*, 0x8) = 0;
        M2C_FIELD(obj, u16*, 0xA) = x;
        x = F(u16, 0xE);
        M2C_FIELD(obj, u16*, 0xC) = 0;
        M2C_FIELD(obj, void**, 0x7C) = self;
        M2C_FIELD(obj, u16*, 0xE) = x;
    }
    F(s8, 0x88) = 0;
    F(s8, 0x89) = 0;
    F(s16, 0x86) = 0;
    F(s8, 0x8A) = 0;
    F(s8, 0x8B) = 0;
    F(s8, 0x8C) = 0;
    F(s8, 0x8D) = 0;
    F(s16, 0x84) = 0;
    F(s8, 6) = 0;
    F(s8, 7) = 0;
}
