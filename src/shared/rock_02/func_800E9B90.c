#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

void func_800E9B90(void) {
    if (D_800970AA > 0x800) {
        background_objects[1].unk4 = 2;
        background_objects[1].unk40 = 0;
        background_objects[1].unk42 = 0;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4 = 2;
        background_objects[2].unk40 = 0;
        background_objects[2].unk42 = 0;
        background_objects[2].unk4C = 1;
        return;
    }
    if (background_objects[1].unk4 == 2) {
        background_objects[1].unk4 = 1;
        background_objects[1].unk40 = 0;
        background_objects[1].unk42 = 0x230;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4 = 3;
        background_objects[2].unk40 = 0;
        background_objects[2].unk42 = 0x280;
        background_objects[2].unk4C = 1;
    }
}
