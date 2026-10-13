#include "common.h"
#include "mmx6/x4.h"

extern struct X4_MiscObj D_800CD410[];

void* func_8002C530(void) {
    s8* p;
    s8* q;
    s32 k;

    for (p = (s8*)D_800CD410; p < (s8*)D_800CD410 + 0x2400; p += 0x60) {
        if (*p == 0) {
            q = p;
            for (k = 0x5F; k != -1; k--) {
                *q++ = 0;
            }
            return p;
        }
    }
    return 0;
}
