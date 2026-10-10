#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003AD18(void* arg0);
M2C_UNK func_8003CCBC();
void func_8003CF24(s32, s32, s32);
M2C_UNK func_8003D510(M2C_UNK, M2C_UNK, s8, M2C_UNK);
void func_8003D598(void*);
extern u16 D_80073CFC[];
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;

void func_8003C1AC(void* arg0) {
    s8* e = (s8*)&D_800CCED0;
    u8 t;
    if (M2C_FIELD(e, s8*, 0xC) == 0xC) {
        if (M2C_FIELD(e, s8*, 0xD) == 0) {
            M2C_FIELD(arg0, u16*, 0xE) = D_80073CFC[M2C_FIELD(e, s8*, 0x1D)];
        } else {
            M2C_FIELD(arg0, u16*, 0xE) = 0x1CB;
        }
    }
    {
        s8* f = (s8*)&D_800CCED0;
        t = M2C_FIELD(f, u8*, 0x5E);
        M2C_FIELD(arg0, u8*, 0xE7) = t;
        M2C_FIELD(arg0, s32*, 0xEC) =
            *(s32*)(f - -(M2C_FIELD(arg0, s8*, 2) << 2) + 0x74);
        if (t == 2) {
            M2C_FIELD(arg0, u8*, 0xC9) = 0;
            func_8003D510(1, 0x1B, 5, 0);
            func_8003CF24(2, 0x19, 1);
            func_8003CF24(2, 0x18, 1);
        } else {
            M2C_FIELD(arg0, u8*, 0xC9) = M2C_FIELD(f, u8*, 0x60);
        }
    }
    func_8003D598(arg0);
    if (M2C_FIELD(arg0, s32*, 0xEC) & 8) {
        M2C_FIELD(arg0, s32*, 0x134) -= 0x1080;
    }
    if (M2C_FIELD(arg0, u8*, 0xE7) == 2) {
        M2C_FIELD(arg0, s32*, 0x110) = 0;
    }
    if (M2C_FIELD(arg0, s32*, 0xEC) & 0x10) {
        M2C_FIELD(arg0, s32*, 0x104) += 0x1A000;
        M2C_FIELD(arg0, s32*, 0x108) += 0x10800;
        M2C_FIELD(arg0, s32*, 0x10C) += 0xC00;
        M2C_FIELD(arg0, s32*, 0x12C) += 0x10800;
        M2C_FIELD(arg0, s32*, 0x130) += 0x10800;
    }
    if (M2C_FIELD(arg0, s32*, 0xEC) & 4) {
        M2C_FIELD(arg0, s32*, 0xF0) += 0x4000;
        M2C_FIELD(arg0, s32*, 0xF4) += 0x10000;
    }
    if (M2C_FIELD(arg0, s8*, 2) != 0) {
        M2C_FIELD(arg0, u16*, 0xE) -= 1;
    }
    M2C_FIELD(arg0, s16*, 0xC) = 0;
    M2C_FIELD(e, s8*, 0x1C) = 0;
    func_8003CCBC(arg0);
    func_8003AD18(arg0);
    {
        register s32 k asm("$2") = 4;
        M2C_FIELD(arg0, u8*, 0x92) = k;
    }
    M2C_FIELD(arg0, u8*, 0x71) |= 8;
    D_800971F8[0].unk44 = 1;
    D_800971F8[1].unk44 = 1;
    D_800971F8[2].unk44 = 1;
}
