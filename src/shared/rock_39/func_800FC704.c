#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800970AA;
extern struct X4_BackgroundObj D_800971F8[3];
extern u16 D_80097202;
extern u8 D_80100D18[][7];
extern u16 D_80100D28[][2];

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800FC704(struct X4_AnimatedObj* arg0) {
    s32 sw;
    s32 d;

    sw = D_80100D18[F(s8, 0x94)][arg0->unk7];
    switch (sw) {
    case 1:
        if ((F(s32, 0x84) & 0xF) == 0) {
            F(u16, 0x90) = D_80100D28[sw][0];
        } else {
            F(u16, 0x92) = D_80100D28[sw][1];
            d = D_800970AA - (s16)D_80097202;
            if (d < 0x21) {
                F(u16, 0x90) = 0x20;
            } else if (d >= 0x90) {
                F(u16, 0x90) = 0x90;
            } else {
                F(u16, 0x90) = (D_800970AA - D_80097202) & 0xFF0;
            }
        }
        F(u16, 0x92) = D_80100D28[sw][1];
        break;
    case 4:
        if ((F(s32, 0x84) & 0xF0) == 0) {
            F(u16, 0x90) = D_80100D28[sw][0];
        } else {
            F(u16, 0x92) = D_80100D28[sw][1];
            d = D_800970AA - (s16)D_80097202;
            if (d < 0xB1) {
                F(u16, 0x90) = 0xB0;
            } else if (d >= 0x110) {
                F(u16, 0x90) = 0x110;
            } else {
                F(u16, 0x90) = (D_800970AA - D_80097202) & 0xFF0;
            }
        }
        F(u16, 0x92) = D_80100D28[sw][1];
        break;
    case 2:
    case 3:
    case 5:
    case 6:
        F(u16, 0x90) = D_80100D28[sw][0];
        F(u16, 0x92) = D_80100D28[sw][1];
        break;
    case 0:
        F(u16, 0x90) = F(u16, 0x88) - D_800971F8[0].x_pos.i.hi;
        F(u16, 0x92) = F(u16, 0x8A) - D_800971F8[0].y_pos.i.hi;
        break;
    }
    arg0->unk6++;
}
