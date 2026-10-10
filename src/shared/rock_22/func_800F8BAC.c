#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
void* func_8002C458();
M2C_UNK func_8002D2B0(s32);
s32 func_8002D2D4();

void func_800F8BAC(void* arg0) {
    void* p;
    void* c;
    s32 v;
    s32 m;
    s32 i;
    s32 off;

    func_80017A04();
    ((void (*)(s32))func_8002D2B0)((s32)arg0);
    p = M2C_FIELD(arg0, void**, 0x7C);
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0 || M2C_FIELD(p, s8*, 6) == 0 ||
        M2C_FIELD(p, s8*, 4) >= 2) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x1B);
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
        return;
    }
    v = M2C_FIELD(arg0, s32*, 0x20);
    if (v > 0) {
        m = M2C_FIELD(arg0, u8*, 0x70) & 1;
        goto test;
    }
    if (v < 0) {
        m = M2C_FIELD(arg0, u8*, 0x70) & 2;
    test:
        if (m != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -v;
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x8E) == 0) {
        off = 0x40;
        M2C_FIELD(arg0, u16*, 0x8E) =
            ((u8)((u32)func_8002D2D4() % 5) + 1) * 10 + 0x3C;
        i = 1;
        M2C_FIELD(arg0, u16*, 0x8E) =
            ((u8)((u32)func_8002D2D4() % 6) + 1) * 10 + 0x1E;
        do {
            c = func_8002C458();
            if (c != 0) {
                M2C_FIELD(c, s8*, 0) = 0x41;
                M2C_FIELD(c, s8*, 1) = 0x1E;
                M2C_FIELD(c, s8*, 2) = 9;
                M2C_FIELD(c, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(c, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(c, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(c, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(c, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
                M2C_FIELD(c, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
                M2C_FIELD(c, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) + off;
                M2C_FIELD(c, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
            }
            i--;
            off += 0x40;
        } while (i >= 0);
    }
}
