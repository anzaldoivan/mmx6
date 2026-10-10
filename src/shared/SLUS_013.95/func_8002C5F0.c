#include "common.h"
#include "mmx6/x4.h"

extern struct X4_MiscObj D_800CD410[];
extern u8 D_800CF7B0[];
extern u8 D_800CF810[];

s8* func_8002C5F0(s8* p, s32 back) {
    if (back == 0) {
        if (p == 0) {
            p = (s8*)D_800CD410;
        } else {
            p += 0x60;
        }
        for (; p < (s8*)D_800CF810; p += 0x60) {
            if (*p == 0) {
                s8* q = p;
                s32 k = 0x5F;
                do {
                    *q = 0;
                    k--;
                    q++;
                } while (k != -1);
                return p;
            }
        }
    } else {
        if (p == 0) {
            p = (s8*)D_800CF7B0;
        } else {
            if (p == (s8*)D_800CD410) {
                return 0;
            }
            p -= 0x60;
        }
        for (; p >= (s8*)D_800CD410; p -= 0x60) {
            if (*p == 0) {
                s8* q = p;
                s32 k = 0x5F;
                do {
                    *q = 0;
                    k--;
                    q++;
                } while (k != -1);
                return p;
            }
        }
    }
    return 0;
}
