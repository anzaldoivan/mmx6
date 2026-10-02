/* Adapted from sozud/mmx4 @29b62af src/main/E47C.c:func_8001E638, AGPL-3.0; proven shared with X6 by exact signature 0bffad427ba7 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_800139F4(s32);

void func_8001DF5C(struct X4_GameInfo* arg0) {
    arg0->unk4--;
    if (arg0->unk4 == 0) {
        func_800139F4(8);
        arg0->mode++;
    }
}
