#include "common.h"

#define M2C_UNK s32

#include "psyq/libsnd.h"

void func_80017488(void) {
    SsStart();
    SsSetMVol(0x7F, 0x7F);
    SsSetSerialAttr(0, 0, 0);
    SsSetSerialVol(0, 0x7F, 0x7F);
}

/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:func_800153D4, AGPL-3.0; proven shared with X6 by exact signature 3313a3f0820f (see THIRD_PARTY.md). */
#include "common.h"
#include "psyq/libsnd.h"

void func_800174D4(u8 arg0) {
    arg0 ? SsSetStereo() : SsSetMono();
}
