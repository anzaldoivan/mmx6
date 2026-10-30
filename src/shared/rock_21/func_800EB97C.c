#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern s16 D_800F2242;

void func_800EB97C(void* arg0) {
    func_8002B410(&D_800EE840, &D_800ED640, 0x100, --D_800F2242, 0x60);
    load_palette(0x70, &D_800EE840, 0x10);
    if (D_800F2242 == 0) {
        *((u8*)arg0 + 1) += 1;
    }
}
