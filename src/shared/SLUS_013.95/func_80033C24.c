#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2); /* extern */
extern struct X4_PlayerObj g_Player;
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;

void func_80033C24(u8* arg0) {
    s32 flag;
    u32 i;
    s32 v;
    s32 w;

    if (!(D_80097420 & 1)) {
        flag = 0;
        if (*(s32*)(arg0 + 0x34) != 0) {
            i = 0;
            do {
                u8* pl = (u8*)&g_Player;
                s16* p = (s16*)(pl + 0xA8) + i;
                if (*p >= *(s16*)(pl + 0x14A)) {
                    *p = *(s16*)(pl + 0x14A);
                } else {
                    *p += 6;
                    if (*(s16*)(pl + 0x14A) < *p) {
                        *p = *(s16*)(pl + 0x14A);
                    } else {
                        flag = 1;
                    }
                }
                i++;
            } while (i < 9);
            if (flag) {
                goto dec;
            }
            {
                u8* e = (u8*)&D_800CCED0;
                // !FAKE: depin: dropping it breaks the match (42/119)
                register s32 t asm("$5");
                v = e[0x65] & 0x7F;
                t = v - 1;
                if (v != 0) {
                    e[0x65] = t;
                } else {
                    arg0[5] = 1;
                    *(s32*)(arg0 + 0x34) = 0;
                }
            }
        } else {
            u8* h = (u8*)&D_800CCED0;
            if (h[0x65] & 0x7F) {
                i = 0;
                do {
                    u8* pl = (u8*)&g_Player;
                    s16* p = (s16*)(pl + 0xA8) + i;
                    if (*p >= *(s16*)(pl + 0x14A)) {
                        *p = *(s16*)(pl + 0x14A);
                    } else {
                        *p += 6;
                        if (*p >= *(s16*)(pl + 0x14A)) {
                            *p = *(s16*)(pl + 0x14A);
                        } else {
                            flag = 1;
                        }
                    }
                    i++;
                } while (i < 9);
                if (flag) {
                dec: {
                    u8* e = (u8*)&D_800CCED0;
                    v = e[0x65];
                    w = v & 0x7F;
                    if (w != 0) {
                        w--;
                    }
                    v = D_80097420 & 3;
                    e[0x65] = w;
                    if (!v) {
                        func_80016C48(0, 0x17, 0);
                    }
                }
                } else {
                    // !FAKE: depin: dropping it breaks the match (117/119)
                    register u8* e asm("$4") = (u8*)&D_800CCED0;
                    // !FAKE: depin: dropping it breaks the match (43/119)
                    register s32 t asm("$5");
                    v = e[0x65] & 0x7F;
                    t = v - 1;
                    if (v != 0) {
                        e[0x65] = t;
                    } else {
                        arg0[5] = 1;
                    }
                }
            } else {
                arg0[5] = 1;
            }
        }
    }
}
