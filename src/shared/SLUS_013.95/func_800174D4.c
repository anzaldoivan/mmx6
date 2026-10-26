/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:func_800153D4, AGPL-3.0; proven shared with X6 by exact signature 3313a3f0820f (see THIRD_PARTY.md). */
#include "common.h"
extern void SsSetMono(void);
extern void SsSetStereo(void);

void func_800174D4(u8 arg0) {
    arg0 ? SsSetStereo() : SsSetMono();
}
