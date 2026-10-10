/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_56_jet_stingray.c:jet_stingray_vortex_finish, AGPL-3.0; proven shared with X6 by exact signature 5870cc71888c (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800E9E80(struct X4_MainObj* self) {
    if (--self->unk7C == 0) {
        self->unk5 = 2;
        self->unk6 = 0;
    }
}
