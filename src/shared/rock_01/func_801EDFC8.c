#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002C9B0();
M2C_UNK move_object(void*);
extern s32 D_8007798C;
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern s32 D_801EE3DC;

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801EDFC8(u8* arg0) {
    struct X4_PlayerObj* pl = &g_Player;
    s16 d;
    u8* scr;

    if (SB(arg0, 4) == 0) {
        d = UH(arg0, 0xA) - background_objects[SB(arg0, 0x14)].x_pos.u.hi;
        if ((u16)(d + 0x10) < 0x161) {
            if (SB(arg0, 2) == 0) {
                B(pl, 7)++;
            }
            B(arg0, 3) = 1;
            scr = SCRATCH_1C;
            W(arg0, 0x3C) = (s32)(scr + W(scr, 0x3C));
            W(arg0, 0x30) = (s32)&D_8007798C;
            H(arg0, 0x40) = 0;
            H(arg0, 0x42) = 0x7802;
            B(arg0, 0x16) = 0x11;
            if (SB(arg0, 2) != 0) {
                H(arg0, 0xE) =
                    background_objects[SB(arg0, 0x14)].y_pos.u.hi - 0x120;
                func_800179A4(arg0, 0xC);
            } else {
                H(arg0, 0xE) =
                    background_objects[SB(arg0, 0x14)].y_pos.u.hi - 0x80;
                W(arg0, 0x50) = (s32)&D_801EE3DC;
                func_800179A4(arg0, 0xB);
            }
            W(arg0, 0x24) = 0xFFF80000;
            B(arg0, 0x64) = B(arg0, 0x45);
            B(arg0, 4)++;
            return;
        }
        // !FAKE: shared despawn call block
        goto block_16;
    }
    func_80017A04(arg0, pl);
    move_object(arg0);
    if (!(D_80097420 & 7)) {
        B(arg0, 0x64)++;
    }
    if (SB(arg0, 0x98) != 0) {
        B(arg0, 0x98) = 0;
        W(arg0, 0x8C)++;
    }
    if ((u32)W(arg0, 0x8C) >= 4U) {
        W(arg0, 0x50) = 0;
    }
    if (SB(arg0, 2) != 0) {
        if (H(arg0, 0xE) >=
            background_objects[SB(arg0, 0x14)].y_pos.i.hi + 0x190) {
        block_16:
            func_8002C9B0(arg0);
        }
    } else if (H(arg0, 0xE) >=
               background_objects[SB(arg0, 0x14)].y_pos.i.hi + 0x170) {
        func_8002C9B0(arg0);
    }
}
