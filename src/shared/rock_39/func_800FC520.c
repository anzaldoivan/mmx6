#include "common.h"
#include "mmx6/x4.h"

#define O6 (*(u8*)(arg0 + 6))
#define OX (*(s16*)(arg0 + 0xA))
#define OY (*(s16*)(arg0 + 0xE))
#define O15 (*(u8*)(arg0 + 0x15))
#define OVX (*(s32*)(arg0 + 0x20))
#define OVY (*(s32*)(arg0 + 0x24))

void func_8002D2B0();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_BackgroundObj background_objects[3];

#define BGX background_objects[0].x_pos.i.hi
#define BGY background_objects[0].y_pos.i.hi
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800FC520(u8* arg0) {
    s32 a;

    if (O15 == 0) {
        s32 t = OY - 0x90;
        s32 u = OX - 0x30;
        a = func_80065B74(t - BGY, BGX - u);
    } else {
        s32 t = OY - 0x90;
        s32 u = OX - 0x110;
        a = func_80065B74(t - BGY, BGX - u);
    }
    OVX = func_80065A14(a) << 6;
    OVY = func_80065944(a) << 6;
    do {
        func_8002D2B0(arg0);
    } while (0);
    if (O15 == 0) {
        s32 u = OX - 0x30;
        if (ABS(BGX - u) < 5) {
            s32 t = OY - 0x90;
            if (ABS(BGY - t) < 5) {
                OX = BGX + 0x30;
                OY = BGY + 0x90;
                O6++;
            }
        }
    } else {
        s32 u = OX - 0x110;
        if (ABS(BGX - u) < 5) {
            s32 t = OY - 0x90;
            if (ABS(BGY - t) < 5) {
                OX = BGX + 0x110;
                OY = BGY + 0x90;
                O6++;
            }
        }
    }
}
#undef O6
#undef OX
#undef OY
#undef O15
#undef OVX
#undef OVY
