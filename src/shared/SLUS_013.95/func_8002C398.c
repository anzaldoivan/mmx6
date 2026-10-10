#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80091298[];

struct X4_VisualObj* func_8002C398(void) {
    u8* p;

    for (p = D_80091298; p < D_80091298 + 0x2A00; p += 0x70) {
        if (*(s8*)p == 0) {
            s8* q = (s8*)p;
            s32 k;
            for (k = 0x6F; k != -1; k--) {
                *q++ = 0;
            }
            return (struct X4_VisualObj*)p;
        }
    }
    return 0;
}
