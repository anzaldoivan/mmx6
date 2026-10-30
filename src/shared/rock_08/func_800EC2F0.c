#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003AD18(void* arg0);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;
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
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(p, s16*, 0xA) = a;
    } else {
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(p, s16*, 0xA) = b;
    }
    if (M2C_FIELD(arg0, s16*, 0x80) >= 0x1D) {
        struct X4_PlayerObj* p;
        s32 base;
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        p = &g_Player;
        M2C_FIELD(p, s16*, 0xA) = D_800F5754
            [D_800F5644[M2C_FIELD(arg0, s8*, 0x2) +
                        (base =
                             g_playthrough_state.character_state.bytes[10] * 4 -
                             1)]][0];
        M2C_FIELD(p, s32*, 0x68) = M2C_FIELD(arg0, s32*, 0x88);
        func_8003AD18(p);
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk19 = 0;
        M2C_FIELD(arg0, u8*, 0x0) &= 0xF7;
        M2C_FIELD(arg0, u8*, 0x7) += 1;
    }
}
