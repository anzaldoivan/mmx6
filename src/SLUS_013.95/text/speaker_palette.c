#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

s32 func_80021AF0(s32 arg0);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
extern u8 speaker_colors[];
extern u8 D_8006E484[];

// 0x80022838 load_speaker_palette: loads the palette of the speaker of text arg0 into CLUT slot 0x16, or 0x5F in wide mode.
// basis: xref open_text_box (docs/leads/derived.tsv:12)
// callers: open_text_box
void load_speaker_palette(s32 arg0) {
    u8* temp_v0;

    temp_v0 = D_8006E484 + (speaker_colors[func_80021AF0(arg0)] << 5);
    if (g_wide_mode == 0) {
        load_palette(0x16, (M2C_UNK*)temp_v0, 1);
        return;
    }
    load_palette(0x5F, (M2C_UNK*)temp_v0, 1);
}
