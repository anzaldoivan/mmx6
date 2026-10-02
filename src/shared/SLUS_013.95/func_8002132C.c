/* Adapted from sozud/mmx4 @29b62af src/main/afterimage.c:func_800AE88C, AGPL-3.0; proven shared with X6 by exact signature fb1027ecedab (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_80071388[])(struct X4_UnkObj*, struct X4_PlayerObj*);

void func_8002132C(struct X4_UnkObj* arg0, struct X4_PlayerObj* arg1) {
    if (arg1->afterimage == 0) {
        arg0->on_screen = 0;
        arg0->state = 0;
        return;
    }

    D_80071388[arg0->unk5](arg0, arg1);
}
