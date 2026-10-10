/* Adapted from sozud/mmx4 @29b62af src/main/E47C.c:func_8001E6BC, AGPL-3.0; proven shared with X6 by exact signature 3affa1eca32f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s8 D_80097424;
#define D_80097424 (*(s8(*)[]) & D_80097424)
void func_8001D218();

void func_8001DFDC(struct X4_GameInfo* arg0) {
    if (D_80097424[0] == 0) {
        arg0->unkD = 1;
        func_8001D218();
        arg0->mode = 0;
        arg0->unk0++;
    }
}
#undef D_80097424
