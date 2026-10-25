#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80029F38();
M2C_UNK func_8002C9B0();
extern s8 D_8008EAB0;
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEED;

void func_800EDBB8(s32 arg0) {
    u16 oy;
    u16 ox;

    if (g_Player.unk5 == 0x14) {
        D_8008EAB0 = 1;
        oy = background_objects[0].y_pos.i.hi;
        ox = background_objects[0].x_pos.i.hi;
        background_objects[1].unk4 = 5;
        background_objects[0].y_pos.i.hi = 0x3B0;
        background_objects[1].y_pos.i.hi = 0x3C0;
        background_objects[2].y_pos.i.hi = 0x3B0;
        background_objects[0].unk24 = 0x17C0;
        background_objects[0].unk1C = 0x17C0;
        background_objects[1].x_pos.i.hi = 0;
        background_objects[0].unk4C = 1;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4C = 1;
        background_objects[0].unk26 = 0;
        background_objects[0].unk1E = 0;
        background_objects[0].unk2A = 0x3B0;
        background_objects[0].unk22 = 0x3B0;
        background_objects[0].unk28 = 0x3B0;
        background_objects[0].unk20 = 0x3B0;
        D_800CCEED = 1;
        background_objects[0].x_pos.i.hi = ox - 0x1240;
        background_objects[2].x_pos.i.hi = background_objects[0].x_pos.i.hi / 2;
        {
            s16 d = g_Player.x_pos.i.hi - ox;
            g_Player.x_pos.i.hi = d + background_objects[0].x_pos.i.hi;
        }
        {
            s16 d = g_Player.y_pos.i.hi - oy;
            g_Player.y_pos.i.hi = d + background_objects[0].y_pos.i.hi;
        }
        {
            s16 d = g_Player.unk18.i.hi - ox;
            g_Player.unk18.i.hi = d + background_objects[0].x_pos.i.hi;
        }
        {
            s16 d = g_Player.unk1C.i.hi - oy;
            g_Player.unk1C.i.hi = d + background_objects[0].y_pos.i.hi;
        }
        func_80029F38(background_objects[0].x_pos.i.hi - 0x30,
                      background_objects[0].x_pos.i.hi + 0x170, 0x380, 0x4D0,
                      0);
        func_8002C9B0(arg0);
    }
}
