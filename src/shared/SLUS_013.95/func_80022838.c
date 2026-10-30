#include "common.h"
#define M2C_UNK s32

s32 func_80021AF0(s32 arg0);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
extern u8 speaker_colors[];
extern u8 D_8006E484[];
extern u16 g_wide_mode;

void func_80022838(s32 arg0) {
    u8* temp_v0;

    temp_v0 = D_8006E484 + (speaker_colors[func_80021AF0(arg0)] << 5);
    if (g_wide_mode == 0) {
        load_palette(0x16, (M2C_UNK*)temp_v0, 1);
        return;
    }
    load_palette(0x5F, (M2C_UNK*)temp_v0, 1);
}
