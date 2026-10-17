#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EC584(struct X4_MainObj* arg0) {
    u32 t = D_80097420;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            D_800971F8[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            D_800971F8[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            D_800971F8[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        D_800971F8[1].unk4C = 1;
    }
}
