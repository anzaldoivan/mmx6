#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800FD530;
extern M2C_UNK D_800FD730;
extern M2C_UNK D_800FD930;
extern M2C_UNK D_800FD9D0;
extern s16 D_800FDA70;

void func_800EDF24(u8* arg0) {
    func_8002B410(&D_800FD730, &D_800FD530, 0x100, --D_800FDA70, 0x60);
    load_palette(0x3C, &D_800FD730, 0x10);
    func_8002B410(&D_800FD9D0, &D_800FD930, 0x50, D_800FDA70, 0x60);
    load_palette(0x60, &D_800FD9D0, 5);
    if (D_800FDA70 == 0) {
        load_palette(0x3C, &D_800FD530, 0x10);
        load_palette(0x60, &D_800FD930, 5);
        arg0[7] = 4;
        arg0[6]++;
    }
}
