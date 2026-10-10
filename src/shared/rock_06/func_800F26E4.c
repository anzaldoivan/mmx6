/* Adapted from sozud/mmx4 @29b62af src/main/mech.c:func_8003F648, AGPL-3.0; proven shared with X6 by exact signature 020323399ced (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_800F3A5C[])(struct X4_RideArmorObj*);

void func_800F26E4(struct X4_RideArmorObj* arg0) {
    if (!(arg0->unk94.bytes.unk97 & 2)) {
        D_800F3A5C[arg0->unk6](arg0);
    }
}
