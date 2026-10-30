#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EB4FC(struct X4_MainObj* arg0) {
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
    if (!(D_80097420 & 1)) {
        background_objects[1].unk42++;
    }
    if (--arg0->unk7E == 0) {
        func_8002943C(0xA, 2, 2);
        arg0->unk7E = 0xA;
    }
    if ((s16)background_objects[1].unk42 >= -0x1F) {
        *(s16*)&background_objects[1].unk42 = -0x20;
        arg0->unk7C = 0;
        arg0->unk6++;
        play_sound(5, 3, arg0);
    }
}
