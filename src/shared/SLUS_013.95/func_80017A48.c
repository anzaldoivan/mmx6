/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:clear_vram_rect_ptrs, AGPL-3.0; proven shared with X6 by exact signature fd1585f50292 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_RectPtrPair D_800C11C0[];
extern struct X4_RectPtrPair* D_80097790;

void func_80017A48(void) {
    u32 i;
    struct X4_RectPtrPair* ptr;

    ptr = &D_800C11C0[0];
    D_80097790 = ptr;

    for (i = 0; i < 8; i++) {
        ptr->rect.x = 0;
        ptr->rect.y = 0;
        ptr->rect.w = 0;
        ptr->rect.h = 0;
        ptr->ptr = NULL;
        ptr++;
    }
}
