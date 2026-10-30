#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
void* func_8002BCCC(void*, s32);
void* func_8002C458();
s32 random_byte();
extern s32 D_80097420;

void func_800F6418(void* arg0) {
    void* s2;
    void* p;
    void* q;

    s2 = M2C_FIELD(arg0, void**, 0x84);
    if (M2C_FIELD(s2, s8*, 6) >= 4 && !(D_80097420 & 7)) {
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x1E;
            M2C_FIELD(p, u8*, 2) = (random_byte() & 7) + 0xB;
            M2C_FIELD(p, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(p, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(p, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(p, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(p, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(p, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(p, void**, 0x7C) = arg0;
        }
    }
    func_80017A04(arg0);
    if (M2C_FIELD(s2, s8*, 6) == 5) {
        q = func_8002BCCC(arg0, 0);
        if (q != 0) {
            M2C_FIELD(q, u8*, 0) = 0x41;
            M2C_FIELD(q, u8*, 1) = 0x3C;
            M2C_FIELD(q, u8*, 2) = M2C_FIELD(arg0, u8*, 2) + 2;
            M2C_FIELD(q, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(q, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(q, u8*, 0x5C) = M2C_FIELD(arg0, u8*, 0x5C);
            M2C_FIELD(q, void**, 0x84) = arg0;
            M2C_FIELD(q, void**, 0x88) = M2C_FIELD(arg0, void**, 0x84);
        }
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
