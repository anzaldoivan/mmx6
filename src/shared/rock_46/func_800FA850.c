#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA850(u8* arg0) {
    D_800FD120++;
    ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
        &D_800FBF20, &D_800FAD20, 0x300, D_800FD120);
    func_8002B3D4(0x90, &D_800FBF20, 0x30);
    if (D_800FD120 >= 0x20) {
        D_8008EAB0 = 1;
        background_objects[1].unk3 = 0;
        background_objects[2].x_pos.i.hi = 0;
        background_objects[2].y_pos.i.hi = 0x300;
        background_objects[2].unk4C = 1;
        {
            s32 t;
            t = arg0[1];
            *(u16*)(arg0 + 8) = 0x12;
            *(u16*)(arg0 + 4) = 0;
            *(u16*)(arg0 + 0xA) = 1;
            t++;
            arg0[1] = t;
        }
    }
}
