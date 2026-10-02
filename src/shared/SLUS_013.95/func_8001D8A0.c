/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D64C, AGPL-3.0; proven shared with X6 by exact signature 370ee8910a36 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_800139F4(s32);

void func_8001D8A0(struct X4_GameInfo* arg0) {
    if (--arg0->unk4 == 0) {
        arg0->mode++;
        func_800139F4(8);
    }
}
