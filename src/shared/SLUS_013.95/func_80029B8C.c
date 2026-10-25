#include "common.h"
#include "mmx6/x4.h"

extern s16** D_80073300[];
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj D_800CCED0;

void func_80029B8C(void) {
    struct X4_BackgroundObj* bg;
    s16* src;

    src = D_80073300[D_800CCED0.stage * 2 + D_800CCED0.substage]
                    [D_800CCED0.checkpoint];
    {
        // !FAKE: depin: dropping it breaks the match (95/99)
        register s32 v0 asm("$3");
        s32 v1;
        v0 = src[0] << 16;
        g_Player.x_pos.val = v0;
        v1 = src[1] << 16;
        g_Player.unk18.val = v0;
        g_Player.y_pos.val = v1;
        g_Player.unk1C.val = v1;
    }
    g_Player.unk15 = ((u8*)src)[0x18];
    bg = background_objects;
    bg->x_pos.i.hi = src[2];
    bg->unk14.i.hi = src[2];
    bg->y_pos.i.hi = src[3];
    bg->unk18.i.hi = src[3];
    bg->unk1E = src[8];
    bg->unk26 = src[8];
    bg->unk1C = src[9];
    bg->unk24 = src[9];
    bg->unk22 = src[10];
    bg->unk2A = src[10];
    bg->unk20 = src[11];
    bg->unk28 = src[11];
    bg++;
    {
        s32 a;
        s32 b;
        bg->unk40 = a = (u16)src[13];
        bg->unk42 = b = (u16)src[14];
        bg->unk14.i.hi = bg->x_pos.i.hi = a + src[4];
        bg->unk18.i.hi = bg->y_pos.i.hi = b + src[5];
    }
    bg++;
    {
        s32 a;
        // !FAKE: depin: dropping it breaks the match (88/99)
        register s32 b asm("$7");
        bg->unk40 = a = (u16)src[15];
        bg->unk42 = b = (u16)src[16];
        bg->unk14.i.hi = bg->x_pos.i.hi = a + src[6];
        bg->unk18.i.hi = bg->y_pos.i.hi = src[7] + b;
    }
    ((u8*)&g_Player)[0xCE] = ((u8*)src)[0x22];
}
#undef g_Player
