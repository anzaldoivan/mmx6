#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800ED240;
extern M2C_UNK D_800ED440;
extern s16 D_800F2240;

void func_800EA6A4(u8* arg0) {
    s32 flag;

    if ((*(s16*)(arg0 + 4))++ >= 0x1E) {
        *(s16*)(arg0 + 4) = 0;
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag) {
        s32 i;

        D_800F2240 = 0;
        func_8002B410(&D_800ED440, &D_800ED240, 0x10, 0, 0x60);
        load_palette(0x60, &D_800ED440, 0x10);
        for (i = 0; i < 0x10; i++) {
            ((u16*)&D_800ED440)[i] = ((u16*)&D_800ED240)[i] & 0x7FFF;
        }
        load_palette(0x60, &D_800ED440, 0x10);
        background_objects[0].x_pos.u.hi = 0x1600;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 0;
        arg0[1]++;
    }
}
