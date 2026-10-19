#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800663FC(M2C_UNK*, M2C_UNK*);
extern s16 D_80071E70[][4];
extern s8 D_8008EAB0;
#define D_8008EAB0 (*(u8*)&D_8008EAB0)
extern u16 D_80090D6A;

#define SCRATCH_44 (*(M2C_UNK**)0x1F800044)

void func_80027A50(void) {
    if (D_8008EAB0 == 1) {
        func_800663FC((M2C_UNK*)D_80071E70[D_80090D6A], SCRATCH_44);
        D_8008EAB0 = 2;
    }
}
#undef D_8008EAB0
