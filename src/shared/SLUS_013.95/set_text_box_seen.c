#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 D_8007A124[];

// 0x80053440 set_text_box_seen: sets the seen bit of text box arg0 for the current stage.
// basis: code src/shared/rock_11/func_800F23D8.c:24 via=set_text_box_seen
// callers: func_800F23D8, func_800FB414
M2C_UNK set_text_box_seen(M2C_UNK arg0) {
    s32 b = 1 << arg0;
    u16* h = (u16*)((u8*)&g_playthrough_state + 0x9E) +
             D_8007A124[g_playthrough_state.substage +
                        g_playthrough_state.stage * 2];
    *h |= b;
}
