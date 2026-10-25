#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
void* func_8002C458();
extern u8 D_80093C98[];

void func_800ECC38(void* arg0) {
    s8* p;
    s8* end;
    u32 n;
    s8* o;
    // !FAKE: depin: dropping it breaks the match (101/103)
    register u16 t asm("$2");

    func_80017A04();
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0xA1) {
        goto fail;
    }
    p = (s8*)D_80093C98;
    end = p + 0x1400;
    n = 0;
    for (; p < end; p += 0xA0) {
        if (*p != 0 && (*(s32*)p & 0xFFFF00) == 0x21B00) {
            n++;
        }
    }
    if (n >= 8) {
    fail:
        func_800179A4(arg0, 4);
        t = M2C_FIELD(arg0, u8*, 0x6) + 1;
        M2C_FIELD(arg0, u8*, 0x6) = t;
    } else if ((s16)(M2C_FIELD(arg0, s16*, 0x7C) % 20) == 0) {
        o = func_8002C458();
        if (o != 0) {
            M2C_FIELD(o, s8*, 0x0) = 0x41;
            M2C_FIELD(o, s8*, 0x1) = 0x1B;
            M2C_FIELD(o, s8*, 0x2) = 2;
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(o, s32*, 0x8) = M2C_FIELD(arg0, s32*, 0x8);
            M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(o, void**, 0x7C) = arg0;
        }
    }
}
