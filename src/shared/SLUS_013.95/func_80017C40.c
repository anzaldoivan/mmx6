#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

extern s32 D_8006E360;
extern u16 D_80097798[];
extern u16 D_8009E1B0[];
extern u8 D_800C4560;

#define SPAD28 (*(s32*)0x1F800028)

void func_80017C40(void) {
    if (D_800C4560 != 0) {
        if (D_800C4560 & 1) {
            LoadImage(&D_8006E360, (M2C_UNK*)SPAD28);
        }
        if (D_800C4560 & 2) {
            LoadImage(&D_8006E360, (M2C_UNK*)D_80097798);
        }
        if (D_800C4560 & 8) {
            LoadImage(&D_8006E360, (M2C_UNK*)D_8009E1B0);
        }
        D_800C4560 = 0;
    }
}
