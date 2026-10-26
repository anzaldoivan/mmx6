/* Adapted from sozud/mmx4 @807a01b src/main/E47C.c:func_8001E6BC, AGPL-3.0; proven shared with X6 by exact signature 3affa1eca32f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
/* siblings in the same TU declare it as s32; view it as the upstream state block */
extern s32 D_80097420;
#define D_80097420 (*(struct X4_MainBssState*)&D_80097420)
void func_8001D218();

void func_8001DFDC(struct X4_GameInfo* arg0) {
    if (D_80097420.transition.active == 0) {
        arg0->unkD = 1;
        func_8001D218();
        arg0->mode = 0;
        arg0->unk0++;
    }
}
#undef D_80097420
