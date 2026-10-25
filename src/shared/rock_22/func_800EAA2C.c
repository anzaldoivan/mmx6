#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80030ECC(void*);
extern s8 D_80097174;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern u16 D_800FB700[];
extern void (*D_800FB714[])(struct X4_MainObj*);

#define F81(p) (((u8*)(p))[0x81])

void func_800EAA2C(struct X4_MainObj* arg0) {
    u32 t = D_80097420;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    if (D_80097174 == 0) {
        D_800FB714[arg0->unk5](arg0);
        func_80030ECC(arg0);
    }
}
