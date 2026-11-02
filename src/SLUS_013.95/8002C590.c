#include "common.h"

extern u8 D_800964A0[];

s8* func_8002C590(void) {
    s8* p;
    s8* end;
    s8* d;
    s32 k;

    p = (s8*)D_800964A0;
    end = p + 0xC00;
    for (; p < end; p += 0x60) {
        if (*p == 0) {
            d = p;
            for (k = 0x5F; k != -1; k--) {
                *d++ = 0;
            }
            return p;
        }
    }
    return 0;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_MiscObj g_displayed_sprites[];
extern u8 D_800CF7B0[];
extern u8 D_800CF810[];

s8* func_8002C5F0(s8* p, s32 back) {
    if (back == 0) {
        if (p == 0) {
            p = (s8*)g_displayed_sprites;
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
            if (p == (s8*)g_displayed_sprites) {
                return 0;
            }
            p -= 0x60;
        }
        for (; p >= (s8*)g_displayed_sprites; p -= 0x60) {
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

#include "common.h"

extern u8 D_80091298[];
extern u8 D_80093C28[];
#include "mmx6/projectile.h"

s8* func_8002C6F0(s8* arg0, s32 arg1) {
    s8* p;
    s8* q;
    s32 n;

    if (arg1 == 0) {
        if (arg0 == 0) {
            p = (s8*)D_80091298;
        } else {
            p = arg0 + 0x70;
        }
        for (; (u32)p < (u32)g_projectiles; p += 0x70) {
            if (*p == 0) {
                q = p;
                for (n = 0x6F; n != -1; n--) {
                    *q++ = 0;
                }
                return p;
            }
        }
    } else {
        if (arg0 == 0) {
            p = (s8*)D_80093C28;
        } else {
            if (arg0 == (s8*)D_80091298) {
                return 0;
            }
            p = arg0 - 0x70;
        }
        for (; (u32)p >= (u32)D_80091298; p -= 0x70) {
            if (*p == 0) {
                q = p;
                for (n = 0x6F; n != -1; n--) {
                    *q++ = 0;
                }
                return p;
            }
        }
    }
    return 0;
}
