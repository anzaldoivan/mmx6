/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:load_vram_rect_ptrs, AGPL-3.0; proven shared with X6 by exact signature d1adcd118b38 (see THIRD_PARTY.md). */
#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern struct X4_RectPtrPair D_800C11C0[];
extern struct X4_RectPtrPair* D_80097790;

void func_80017A88(void) {
    struct X4_RectPtrPair* cur;
    for (cur = &D_800C11C0[0]; cur < &D_800C11C0[8]; cur++) {
        if (cur->ptr != NULL) {
            LoadImage(&cur->rect, cur->ptr);
        }
    }
    D_80097790 = &D_800C11C0[0];
}
