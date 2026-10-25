#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEF6;
extern M2C_UNK D_800F7798;
extern M2C_UNK D_800F77B8;

void func_800EE478(u8* arg0) {
    if (D_800CCEF6 != 0) {
        *(u16*)(arg0 + 0x14) = 0;
        *(u16*)(arg0 + 0x16) = 0;
        *(u16*)(arg0 + 0x18) = 0;
        {
            u8* bg = (u8*)background_objects;
            *(u16*)(bg + 0x5E) = 0;
            *(u16*)(bg + 0x62) = 0;
            bg[0xA0] = 1;
        }
        *(u16*)(arg0 + 0x1E) = 1;
        *(u16*)(arg0 + 0x1A) = 0;
        func_8002B410(&D_800F77B8, &D_800F7798, 0x10, 0x3C, 0x3C);
        func_8002B3D4(*(u16*)(arg0 + 0x20) + 0x60, &D_800F77B8, 1);
        func_80016C48(5, 4, 0);
        arg0[4]++;
    }
}
