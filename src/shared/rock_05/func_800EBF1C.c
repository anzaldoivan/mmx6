#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800743DC;
extern struct X4_PlayerObj g_Player;
extern s32 D_800F3FF4;
extern s32 D_800F3FF8;
extern s32 D_800F3FFC;
extern s32 D_800F4000;
extern s32 D_800F4004;

#define BF_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define BF_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define BF_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define BF_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define BF_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_800EBF1C(void* arg0) {
    s32 ang;
    s8 t;

    BF_U8(arg0, 0x16) = 4;
    t = BF_S8(arg0, 0x2);
    BF_U8(arg0, 0x6) = 0;
    BF_S16(arg0, 0x8C) = 0;
    BF_PTR(arg0, 0x68) = 0;
    BF_PTR(arg0, 0x54) = 0;
    BF_PTR(arg0, 0x50) = 0;
    BF_U8(arg0, 0x4)++;
    if (t == 0) {
        func_800179A4(arg0, 0xA);
        BF_U8(arg0, 0x5) = 0;
        BF_U8(arg0, 0x15) = 0x40;
    } else if (t == 1) {
        func_800179A4(arg0, 0xA);
        BF_U8(arg0, 0x5) = 0;
        BF_U8(arg0, 0x15) = 0;
    } else if (t == 2) {
        func_800179A4(arg0, 0xB);
        BF_U8(arg0, 0x5) = 0;
        BF_U8(arg0, 0x15) = 0;
    } else if (t == 3) {
        func_800179A4(arg0, 0xC);
        BF_U8(arg0, 0x5) = 0;
        BF_U8(arg0, 0x15) = 0;
    } else if (t == 4) {
        BF_U8(arg0, 0x60) = 4;
        BF_U8(arg0, 0x5C) = 2;
        ang = func_80065B74(g_Player.y_pos.i.hi - BF_S16(arg0, 0xE),
                            g_Player.x_pos.i.hi - BF_S16(arg0, 0xA));
        BF_S32(arg0, 0x20) = func_80065A14(ang) << 6;
        BF_S32(arg0, 0x24) = -func_80065944(ang) << 6;
        BF_PTR(arg0, 0x50) = &D_800F3FF4;
        BF_PTR(arg0, 0x54) = &D_800F3FF8;
        BF_PTR(arg0, 0x68) = &D_800F3FFC;
        BF_PTR(arg0, 0x58) = &D_800743DC;
        func_800179A4(arg0, 9);
        BF_U8(arg0, 0x5) = 1;
    } else if (t == 5) {
        BF_U8(arg0, 0x60) = 4;
        BF_U8(arg0, 0x5C) = 2;
        ang = func_80065B74(g_Player.y_pos.i.hi - BF_S16(arg0, 0xE),
                            g_Player.x_pos.i.hi - BF_S16(arg0, 0xA));
        BF_S32(arg0, 0x20) = func_80065A14(ang) << 6;
        BF_S32(arg0, 0x24) = -func_80065944(ang) << 6;
        BF_PTR(arg0, 0x50) = &D_800F3FF4;
        BF_PTR(arg0, 0x54) = &D_800F3FF8;
        BF_PTR(arg0, 0x68) = &D_800F3FFC;
        BF_PTR(arg0, 0x58) = &D_8007433C;
        func_800179A4(arg0, 9);
        BF_U8(arg0, 0x5) = 1;
    } else if (t == 6) {
        BF_U8(arg0, 0x60) = 0x7F;
        BF_PTR(arg0, 0x50) = &D_800F4000;
        BF_U8(arg0, 0x5) = 2;
    } else if (t == 7) {
        BF_U8(arg0, 0x60) = 0x7F;
        BF_PTR(arg0, 0x50) = &D_800F4004;
        BF_U8(arg0, 0x5) = 2;
    }
}
