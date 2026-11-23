#include "common.h"
#include "mmx6/globals.h"

extern u8 D_8009E150[];

s8* func_8002C850(s8* p, s32 back) {
    if (back == 0) {
        if (p == 0) {
            p = (s8*)g_class6_slots;
        } else {
            p += 0x60;
        }
        for (; p < (s8*)D_8009E1B0; p += 0x60) {
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
            p = (s8*)D_8009E150;
        } else {
            if (p == (s8*)g_class6_slots) {
                return 0;
            }
            p -= 0x60;
        }
        for (; p >= (s8*)g_class6_slots; p -= 0x60) {
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
