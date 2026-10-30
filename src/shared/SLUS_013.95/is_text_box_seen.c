#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 D_8007A124[];

// 0x800533F4 is_text_box_seen: tests the seen bit of text box arg0 for the current stage.
// basis: code src/shared/rock_11/func_800F23D8.c:22 via=is_text_box_seen
// callers: func_800F23D8, func_800FB414
s32 is_text_box_seen(M2C_UNK arg0) {
    u8* p;
    u8* t = D_8007A124;
    s32 b;
    s32 i;
    do {
    } while (0);
    i = g_playthrough_state.substage;
    i += g_playthrough_state.stage * 2;
    p = i + t;
    b = (1 << arg0) & 0xFFFF;
    return ((((u16*)&g_playthrough_state) + *p)[0x4F] & b) != 0;
}
