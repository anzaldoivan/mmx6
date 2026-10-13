#include "common.h"

s8* func_8002C590(void);
extern s32 D_8007120C;
extern s8 D_800CCF08;

void func_8001FB90(u8* t, s16 arg1) {
    s8* p;

    if (*t != 0xFF) {
        do {
            p = func_8002C590();
            if (p != 0) {
                p[0] = 1;
                p[1] = 1;
                p[2] = t[0];
                *(s16*)(p + 0xE) = t[1];
                p[7] = t[2];
            }
            t += 3;
        } while (*t != 0xFF);
    }
    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0;
        p[2] = -1;
        *(s32**)(p + 0x50) = &D_8007120C;
        *(s16*)(p + 0xA) = arg1;
    }
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
