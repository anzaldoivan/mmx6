#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800EE904(void* arg0) {
    struct X4_BackgroundObj* bg;
    s32 lim;
    s32 lim2;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 4) >= 4) {
        M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1F) {
        ((void (*)(void*))move_object)(arg0);
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) == 0) {
        if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
            M2C_FIELD(arg0, s16*, 0x7E) = 5;
            M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        }
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    M2C_FIELD(arg0, s8*, 5)++;
    {
        s32 idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        s32 base = SPAD20;
        // !FAKE: depin: dropping it breaks the match (59/145)
        register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);
        M2C_FIELD(arg0, s32*, 0x3C) = base + off;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0xB, off);
    }
    bg = background_objects;
    if (bg->unk1E + 0xC8 < M2C_FIELD(arg0, s16*, 0xA)) {
        func_8003D308(0x14, 0x40);
        g_Player.x_pos.i.hi = M2C_FIELD(arg0, u16*, 0xA) - 0xA0;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        lim = g_Player.x_pos.i.hi - 0x30;
        if (lim < bg->unk26) {
            bg->unk24 = bg->unk26;
        } else if (bg->unk24 < lim) {
            bg->unk26 = bg->unk24;
        } else {
            bg->unk24 = bg->unk26 = g_Player.x_pos.i.hi - 0x30;
        }
        background_objects[0].unk4C = 1;
    } else {
        func_8003D308(0x14, 0);
        g_Player.x_pos.i.hi = M2C_FIELD(arg0, u16*, 0xA) + 0xA0;
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        lim2 = g_Player.x_pos.i.hi - 0x100;
        if (lim2 < bg->unk26) {
            bg->unk24 = bg->unk26;
        } else if (bg->unk24 < lim2) {
            bg->unk26 = bg->unk24;
        } else {
            bg->unk24 = bg->unk26 = g_Player.x_pos.i.hi - 0x100;
        }
        background_objects[0].unk4C = 1;
    }
    M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].y_pos.i.hi + 0xA0;
    g_playthrough_state.enable_boss = 0;
    g_playthrough_state.boss_ptr = 0;
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
#undef g_Player
