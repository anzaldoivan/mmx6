#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_ObjectHeader D_80097420;
#define EE800_FLAGS (*(s32*)&D_80097420)
extern struct X4_EngineObj D_800CCED0;

#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EBFB4(u8* arg0) {
    s32 a;
    s32 b;
    void* t;

    a = FU16(arg0, 0x80) + 1;
    b = FU16(arg0, 0x82) - 1;
    FU16(arg0, 0x80) = a;
    FU16(arg0, 0x82) = b;
    if (!(EE800_FLAGS & 1)) {
        D_800970A0.x_pos.i.hi = a;
    } else {
        D_800970A0.x_pos.i.hi = b;
    }
    if (D_80097420.state == 0) {
        D_800971F8[0].unk44 = 1;
        D_800971F8[1].unk44 = 1;
        D_800971F8[2].unk44 = 1;
        D_800970A0.x_pos.i.hi = FU16(arg0, 0x84);
        t = *(void**)(arg0 + 0x88);
        D_800CCED0.unk10 = 0;
        D_800CCED0.unk11 = 0;
        D_800CCED0.unk12 = 0;
        D_800CCED0.unk13 = 0;
        D_800CCED0.unk14 = 0;
        D_800CCED0.unk15 = 0;
        D_800CCED0.unk16 = 0;
        D_800CCED0.unk17 = 0;
        D_800CCED0.unk19 = 0;
        D_800970A0.unk68 = t;
    }
}
#undef D_800970A0
