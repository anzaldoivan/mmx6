#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

extern s16 D_80071E70[][4];
extern s8 D_8008EAB0;
#define D_8008EAB0 (*(u8*)&D_8008EAB0)
extern u16 D_80090D6A;

#define SCRATCH_44 (*(M2C_UNK**)0x1F800044)

void func_80027A50(void) {
    if (D_8008EAB0 == 1) {
        LoadImage((M2C_UNK*)D_80071E70[D_80090D6A], SCRATCH_44);
        D_8008EAB0 = 2;
    }
}
#undef D_8008EAB0
