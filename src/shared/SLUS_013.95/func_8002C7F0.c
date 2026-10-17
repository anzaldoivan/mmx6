#include "common.h"
#include "mmx6/x4.h"

extern u8 D_8009C9B0[];

struct X4_QuadObj* func_8002C7F0(void) {
    struct X4_QuadObj* p;
    u8* b;
    s32 i;

    for (p = (struct X4_QuadObj*)D_8009C9B0;
         p < (struct X4_QuadObj*)(D_8009C9B0 + 0x1800); p++) {
        if (p->active == 0) {
            b = (u8*)p;
            for (i = sizeof(struct X4_QuadObj) - 1; i != -1; i--) {
                *b++ = 0;
            }
            return p;
        }
    }
    return 0;
}
