#include "common.h"

extern s32 D_800C1220[];
extern s32 D_800C44BC[];
extern u8 D_800C4560;

#define CLEAR_OBJ(p)                                                           \
    {                                                                          \
        s8* q = (p);                                                           \
        s32 n = 0xA3;                                                          \
        do {                                                                   \
            *q++ = 0;                                                          \
        } while (--n != -1);                                                   \
        *(s32*)((p) + 0x50) = 0;                                               \
        *(s32*)((p) + 0x54) = 0;                                               \
        *(s32*)((p) + 0x68) = 0;                                               \
        return (p);                                                            \
    }

void* func_8002BFD0(void* arg0, s32 arg1) {
    s8* p = arg0;

    if (arg1 == 0) {
        if (p == 0) {
            p = (s8*)D_800C1220;
        } else {
            p += 0xA4;
        }
        for (; p < (s8*)&D_800C4560; p += 0xA4) {
            if (*p == 0) {
                CLEAR_OBJ(p);
            }
        }
    } else {
        if (p == 0) {
            p = (s8*)D_800C44BC;
        } else {
            if (p == (s8*)D_800C1220) {
                return 0;
            }
            p -= 0xA4;
        }
        for (; p >= (s8*)D_800C1220; p -= 0xA4) {
            if (*p == 0) {
                CLEAR_OBJ(p);
            }
        }
    }
    return 0;
}
