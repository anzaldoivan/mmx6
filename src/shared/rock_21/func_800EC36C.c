#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern M2C_UNK D_800F1E40;
extern M2C_UNK D_800F2040;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800EC36C(u8* arg0) {
    func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, ++D_800F2244, 0x60);
    func_8002B3D4(0xC0, &D_800F0C40, 0x10);
    func_8002B410(&D_800F2040, &D_800F1E40, 0x10, --D_800F2242, 0x60);
    func_8002B3D4(0x61, &D_800F2040, 1);
    if (D_800F2242 == 0) {
        arg0[1]++;
    }
}
