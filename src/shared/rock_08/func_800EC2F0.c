#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003AD18(void* arg0);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F5644[];
extern s16 D_800F5754[][16];

void func_800EC2F0(void* arg0) {
    s32 a;
    s32 b;

    a = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x80) += 1;
    M2C_FIELD(arg0, u16*, 0x82) = a;
    b = M2C_FIELD(arg0, u16*, 0x84) + 1;
    M2C_FIELD(arg0, u16*, 0x84) = b;
    if (!(D_80097420 & 1)) {
        struct X4_PlayerObj* p = &D_800970A0;
        M2C_FIELD(p, s16*, 0xA) = a;
    } else {
        struct X4_PlayerObj* p = &D_800970A0;
        M2C_FIELD(p, s16*, 0xA) = b;
    }
    if (M2C_FIELD(arg0, s16*, 0x80) >= 0x1D) {
        struct X4_PlayerObj* p;
        s32 base;
        D_800971F8[0].unk44 = 1;
        D_800971F8[1].unk44 = 1;
        p = &D_800970A0;
        M2C_FIELD(p, s16*, 0xA) = D_800F5754
            [D_800F5644[M2C_FIELD(arg0, s8*, 0x2) +
                        (base = D_800CCED0.character_state.bytes[10] * 4 - 1)]]
            [0];
        M2C_FIELD(p, s32*, 0x68) = M2C_FIELD(arg0, s32*, 0x88);
        func_8003AD18(p);
        D_800CCED0.unk10 = 0;
        D_800CCED0.unk11 = 0;
        D_800CCED0.unk12 = 0;
        D_800CCED0.unk13 = 0;
        D_800CCED0.unk14 = 0;
        D_800CCED0.unk15 = 0;
        D_800CCED0.unk17 = 0;
        D_800CCED0.unk19 = 0;
        M2C_FIELD(arg0, u8*, 0x0) &= 0xF7;
        M2C_FIELD(arg0, u8*, 0x7) += 1;
    }
}
