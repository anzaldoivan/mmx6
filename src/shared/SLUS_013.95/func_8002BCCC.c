#include "common.h"

extern s8 D_8008EF48[];
extern s32 D_800C1220[];

#define CLEAR_OBJ(p, BODY)                                                     \
    {                                                                          \
        s8* q = (p);                                                           \
        s32 n = 0x9B;                                                          \
        s32 idx;                                                               \
        s32 m;                                                                 \
        s32 k;                                                                 \
        do {                                                                   \
            *q++ = 0;                                                          \
        } while (--n != -1);                                                   \
        *(s32*)((p) + 0x50) = 0;                                               \
        *(s32*)((p) + 0x54) = 0;                                               \
        *(s32*)((p) + 0x68) = 0;                                               \
        idx = (u32)((p) - D_8008EF48) / 0x9C;                                  \
        m = idx / 32;                                                          \
        for (k = 0; k < 0x50; k++) {                                           \
            BODY                                                               \
        }                                                                      \
        return (p);                                                            \
    }
void* func_8002BCCC(void* arg0, s32 arg1) {
    s8* p = arg0;

    if (arg1 == 0) {
        if (p == 0) {
            p = D_8008EF48;
        } else {
            p += 0x9C;
        }
        for (; p < D_8008EF48 + 0x30 * 0x9C; p += 0x9C) {
            if (*p == 0) {
                CLEAR_OBJ(p, {
                    s32 off = k * 0xA4 + 0x98;
                    *(s32*)((s8*)D_800C1220 + off + m * 4) &=
                        ~(1 << (idx & 0x1F));
                });
            }
        }
    } else {
        if (p == 0) {
            p = D_8008EF48 + 0x2F * 0x9C;
        } else {
            if (p == D_8008EF48) {
                return 0;
            }
            p -= 0x9C;
        }
        for (; p >= D_8008EF48; p -= 0x9C) {
            if (*p == 0) {
                CLEAR_OBJ(p, {
                    s32 off = 0x98 + m * 4;
                    *(s32*)((s8*)D_800C1220 + k * 0xA4 + off) &=
                        ~(1 << (idx & 0x1F));
                });
            }
        }
    }
    return 0;
}
