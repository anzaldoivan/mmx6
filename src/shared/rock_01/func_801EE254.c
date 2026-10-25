#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002C9B0();
M2C_UNK move_object(void*);
extern s32 D_8007798C;
extern struct X4_BackgroundObj background_objects[3];

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801EE254(u8* arg0) {
    struct X4_BackgroundObj* bg;
    s16 d;
    u8* scr;
    s32 t;

    if (SB(arg0, 4) == 0) {
        {
            struct X4_BackgroundObj* p = background_objects;
            bg = p + SB(arg0, 0x14);
        }
        d = UH(arg0, 0xA) - bg->x_pos.u.hi;
        if ((u16)(d + 0x10) >= 0x161) {
            func_8002C9B0(arg0);
            return;
        }
        B(arg0, 3) = 1;
        scr = SCRATCH_1C;
        t = W(scr, 0x3C);
        W(arg0, 0x30) = (s32)&D_8007798C;
        H(arg0, 0x40) = 0;
        H(arg0, 0x42) = 0x7802;
        B(arg0, 0x16) = 0x11;
        W(arg0, 0x3C) = (s32)(scr + t);
        H(arg0, 0xE) = bg->y_pos.u.hi - 0x120;
        ((void (*)())func_800179A4)(arg0, 0xC, bg);
        W(arg0, 0x24) = 0xFFF80000;
        B(arg0, 4)++;
        return;
    }
    func_80017A04(arg0);
    move_object(arg0);
    if (H(arg0, 0xE) >= background_objects[SB(arg0, 0x14)].y_pos.i.hi + 0x190) {
        func_8002C9B0(arg0);
    }
}
