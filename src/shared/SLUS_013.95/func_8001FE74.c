#include "common.h"

s8* func_8002C590(void);
extern s8 D_800CCF08;

void func_8001FE74(void) {
    s8* p;

    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 1;
        p[2] = -1;
        p[0x47] = 0x54;
        if (D_800CCF08 != 0) {
            p[0x47] = 0x51;
        }
        *(s16*)(p + 0xA) = 0x120;
        *(s16*)(p + 0xE) = 0x80;
    }
    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 1;
        p[2] = -1;
        p[0x47] = 0x53;
        if (D_800CCF08 != 0) {
            p[0x47] = 0x52;
        }
        *(s16*)(p + 0xA) = 0x80;
        *(s16*)(p + 0xE) = 0x80;
    }
}
