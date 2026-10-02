/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D698, AGPL-3.0; proven shared with X6 by exact signature 08f62733c4aa (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_8001D8EC(struct X4_GameInfo* arg0) {
    arg0->unkD = 1;
    arg0->unk0 = 0;
    arg0->mode = 0;
    arg0->unk2 = 0;
    arg0->unk3 = 0;
    if (++arg0->unkC == 4) {
        arg0->unkC = 0;
    }
}
