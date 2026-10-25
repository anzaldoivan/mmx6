#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FAA5C;

#define SPAD (*(u8**)0x1F80004C)

void func_800EA09C(struct X4_MainObj* arg0) {
    if (!(arg0->unk7C & 7)) {
        arg0->y_pos.u.hi += 0x20;
        func_80049EBC(arg0, 1, 0x40, 0x20);
        func_80049EBC(arg0, 1, 0x40, 0x20);
        func_80049EBC(arg0, 1, 0x40, 0x20);
        arg0->y_pos.u.hi -= 0x20;
    }
    if (!(arg0->unk7C & 0xF)) {
        arg0->y_pos.u.hi += 0x20;
        ((void (*)(s32, s32*, void*))func_800477E4)(6, &D_800FAA5C, arg0);
        arg0->y_pos.u.hi -= 0x20;
        if (background_objects[0].unk20 == background_objects[0].y_pos.i.hi) {
            func_80029478(0xC, 1, 2);
        }
    }
    if (arg0->unk7C == 0x1E) {
        SPAD[0x83] = 1;
    }
    if (--arg0->unk7C == 0) {
        SPAD[0x82] = 1;
        arg0->unk5 = 5;
        arg0->unk6 = 0;
    }
}

#undef SPAD
