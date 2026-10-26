/* Adapted from sozud/mmx4 @807a01b src/main/object_update.c:func_80021CC8, AGPL-3.0; proven shared with X6 by exact signature a99aed5959d6 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_UnkObj D_800972F8[3];

void func_80020DC8(void) {
    struct X4_UnkObj* var_s0;

    for (var_s0 = &D_800972F8; var_s0 < &D_800972F8[COUNT(D_800972F8)];
         var_s0++) {
        func_80020E1C(var_s0);
    }
}
