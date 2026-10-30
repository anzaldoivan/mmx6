#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

s32 func_8003AD18(void* arg0);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_ObjectHeader D_80097420;
#define EEDB8_FLAGS (*(s32*)&D_80097420)
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F782C[][16];
#define EEDB8_TBL ((u16*)D_800F782C)

#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EEDB8(u8* arg0) {
    s32 a;
    s32 b;
    u8* q;

    F16(arg0, 0x7C)++;
    a = FU16(arg0, 0x80) - 1;
    FU16(arg0, 0x80) = a;
    b = FU16(arg0, 0x82) + 1;
    FU16(arg0, 0x82) = b;
    if (!(EEDB8_FLAGS & 1)) {
        g_Player.x_pos.i.hi = a;
    } else {
        g_Player.x_pos.i.hi = b;
    }
    if (F16(arg0, 0x7C) >= 0x1D) {
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        g_Player.x_pos.i.hi = EEDB8_TBL[F16(arg0, 0x7E) * 16];
        g_Player.unk68 = *(void**)(arg0 + 0x88);
        func_8003AD18(&g_Player);
        q = (u8*)&g_playthrough_state;
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
