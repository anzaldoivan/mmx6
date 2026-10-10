#include "common.h"
#include "mmx6/x4.h"

void func_8003AD18(void* arg0);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800F5910[][16];

#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800ED4B0(u8* arg0) {
    s32 a;
    s32 b;
    u8* q;

    F16(arg0, 0x7C)++;
    a = FU16(arg0, 0x80) - 1;
    FU16(arg0, 0x80) = a;
    b = FU16(arg0, 0x82) + 1;
    FU16(arg0, 0x82) = b;
    if (!(D_80097420 & 1)) {
        D_800970A0.x_pos.i.hi = a;
    } else {
        D_800970A0.x_pos.i.hi = b;
    }
    if (F16(arg0, 0x7C) >= 0x1D) {
        D_800971F8[0].unk44 = 1;
        D_800971F8[1].unk44 = 1;
        D_800971F8[2].unk44 = 1;
        D_800970A0.x_pos.i.hi =
            D_800F5910[D_800CCED0.character_state.bytes[9]][0];
        D_800970A0.unk68 = *(void**)(arg0 + 0x84);
        func_8003AD18(&D_800970A0);
        q = (u8*)&D_800CCED0;
        q[0x10] = 0;
        q[0x11] = 0;
        q[0x12] = 0;
        q[0x13] = 0;
        q[0x14] = 0;
        q[0x15] = 0;
        q[0x16] = 0;
        q[0x17] = 0;
        q[0x19] = 0;
        arg0[0] &= 0xF7;
        arg0[6]++;
    }
}
