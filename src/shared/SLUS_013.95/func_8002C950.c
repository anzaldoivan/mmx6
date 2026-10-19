#include "common.h"
#include "mmx6/x4.h"

extern struct X4_LayerObj D_800C4778[4];

struct X4_LayerObj* func_8002C950(void) {
    struct X4_LayerObj* p;
    u8* b;
    s32 i;

    for (p = D_800C4778; p < &D_800C4778[4]; p++) {
        if (p->active == 0) {
            b = (u8*)p;
            for (i = sizeof(struct X4_LayerObj) - 1; i != -1; i--) {
                *b++ = 0;
            }
            return p;
        }
    }
    return 0;
}
