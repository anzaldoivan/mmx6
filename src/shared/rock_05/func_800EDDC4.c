#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
#define D_80097420 (*(struct X4_ObjectHeader*)&D_80097420)
#define EE800_FLAGS (*(s32*)&D_80097420)
extern struct X4_EngineObj D_800CCED0;

#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EDDC4(u8* arg0) {
    s32 a;
    s32 b;
    void* t;

    a = FU16(arg0, 0x80) + 1;
    b = FU16(arg0, 0x82) - 1;
    FU16(arg0, 0x80) = a;
    FU16(arg0, 0x82) = b;
    if (!(EE800_FLAGS & 1)) {
        g_Player.x_pos.i.hi = a;
    } else {
        g_Player.x_pos.i.hi = b;
    }
    if (D_80097420.state == 0) {
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        g_Player.x_pos.i.hi = FU16(arg0, 0x84);
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
        g_Player.unk68 = t;
    }
}
#undef D_80097420
