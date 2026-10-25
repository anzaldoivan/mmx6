#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FAA5C;
extern u8 D_800FAA98[];
extern u8 D_800FAAA0[];
extern u8 D_800FAAA8[];

void func_800E9F1C(struct X4_MainObj* arg0) {
    switch (arg0->unk2) {
    case 1:
        func_80027BA0(0, 0x1220, 0x370, D_800FAA98);
        break;
    case 2:
        func_80027BA0(0, 0x1300, 0x370, D_800FAAA0);
        break;
    case 3:
        func_80027BA0(0, 0x1340, 0x370, D_800FAAA8);
        break;
    }
    background_objects[0].unk4C = 1;
    arg0->y_pos.u.hi += 0x20;
    func_80049EBC(arg0, 1, 0x40, 0x20);
    func_80049EBC(arg0, 1, 0x40, 0x20);
    func_80049EBC(arg0, 1, 0x40, 0x20);
    func_80049EBC(arg0, 1, 0x40, 0x20);
    ((void (*)(s32, s32*, void*))func_800477E4)(6, &D_800FAA5C, arg0);
    arg0->y_pos.u.hi -= 0x20;
    if (background_objects[0].unk20 == background_objects[0].y_pos.i.hi) {
        func_80029478(8, 4, 2);
    }
    arg0->unk7C = 0x3C;
    arg0->unk6++;
}
