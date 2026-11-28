#include "common.h"

extern s8 g_enemies[];
extern s32 g_class4_slots[];

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
        idx = (u32)((p) - g_enemies) / 0x9C;                                   \
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
            p = g_enemies;
        } else {
            p += 0x9C;
        }
        for (; p < g_enemies + 0x30 * 0x9C; p += 0x9C) {
            if (*p == 0) {
                CLEAR_OBJ(p, {
                    s32 off = k * 0xA4 + 0x98;
                    *(s32*)((s8*)g_class4_slots + off + m * 4) &=
                        ~(1 << (idx & 0x1F));
                });
            }
        }
    } else {
        if (p == 0) {
            p = g_enemies + 0x2F * 0x9C;
        } else {
            if (p == g_enemies) {
                return 0;
            }
            p -= 0x9C;
        }
        for (; p >= g_enemies; p -= 0x9C) {
            if (*p == 0) {
                CLEAR_OBJ(p, {
                    s32 off = 0x98 + m * 4;
                    *(s32*)((s8*)g_class4_slots + k * 0xA4 + off) &=
                        ~(1 << (idx & 0x1F));
                });
            }
        }
    }
    return 0;
}

#include "common.h"
#include "mmx6/globals.h"

extern s8 D_800950A0[];
extern s8 D_80096400[];

s8* func_8002BEC4(s8* p, s32 dir) {
    s8* q;
    s32 i;

    if (dir == 0) {
        if (p == 0) {
            p = D_800950A0;
        } else {
            p += 0xA0;
        }
        for (; p < (s8*)D_800964A0; p += 0xA0) {
            if (*p == 0) {
                q = p;
                i = 0x9F;
                do {
                    *q++ = 0;
                    i--;
                } while (i != -1);
                *(s32*)(p + 0x50) = 0;
                *(s32*)(p + 0x54) = 0;
                *(s32*)(p + 0x68) = 0;
                return p;
            }
        }
    } else {
        if (p == 0) {
            p = D_80096400;
        } else {
            if (p == D_800950A0) {
                return 0;
            }
            p -= 0xA0;
        }
        for (; p >= D_800950A0; p -= 0xA0) {
            if (*p == 0) {
                q = p;
                i = 0x9F;
                do {
                    *q++ = 0;
                    i--;
                } while (i != -1);
                *(s32*)(p + 0x50) = 0;
                *(s32*)(p + 0x54) = 0;
                *(s32*)(p + 0x68) = 0;
                return p;
            }
        }
    }
    return 0;
}

#include "common.h"
#include "mmx6/globals.h"

extern s32 D_800C44BC[];

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
            p = (s8*)g_class4_slots;
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
            if (p == (s8*)g_class4_slots) {
                return 0;
            }
            p -= 0xA4;
        }
        for (; p >= (s8*)g_class4_slots; p -= 0xA4) {
            if (*p == 0) {
                CLEAR_OBJ(p);
            }
        }
    }
    return 0;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_8002C0DC(s32 arg0, s32 arg1_) {
    s8 id = arg0;
    s8 arg1 = arg1_;
    struct X4_EffectObj* effect;
    s8 i;

    if (id >= 0) {
        for (i = 0; i < 0x20; i++) {
            effect = &g_class3_slots[i];
            if (effect->active != 0 && effect->id == id &&
                effect->unk2 == arg1) {
                effect->active = 0;
                effect->id = 0;
                effect->unk2 = 0;
                effect->on_screen = 0;
                effect->state = 0;
                effect->unk5 = 0;
                effect->unk6 = 0;
                effect->unk7 = 0;
            }
        }
    } else {
        id &= 0x7F;
        for (i = 0; i < 0x20; i++) {
            effect = &g_class3_slots[i];
            if (effect->active != 0 && effect->id == id) {
                effect->active = 0;
                effect->id = 0;
                effect->unk2 = 0;
                effect->on_screen = 0;
                effect->state = 0;
                effect->unk5 = 0;
                effect->unk6 = 0;
                effect->unk7 = 0;
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8002C1DC(void) {
    s32 z;
    u8* p;
    s32 n;

    z = 0;
    p = (u8*)&g_playthrough_state;
    n = 0x467;
    do {
        *p = z;
        p++;
    } while (n--);
}

#include "common.h"

void func_8002C208(s8* arg0) {
    s32 z = 0;
    s32 i = 0x153;

    do {
        *arg0++ = z;
    } while (i--);
}

#include "common.h"

#include "mmx6/projectile.h"
#include "mmx6/globals.h"

void func_8002C22C(void) {
    u32 i;
    s32 j;
    u8* p;
    u8 v;

    v = 0;
    for (i = 0; i < 48; i++) {
        p = (u8*)&g_enemies[i * 156];
        j = 155;
        do {
            *p++ = v;
        } while (j-- != 0);
    }
    for (i = 0; i < 32; i++) {
        p = (u8*)&g_projectiles[i];
        j = 159;
        do {
            *p++ = v;
        } while (j-- != 0);
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/objects.c:func_8002AB20, AGPL-3.0; proven shared with X6 by exact signature 7632243f87cd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

void func_8002C2B8() {
    s8 fill = 0;
    u32 i;
    for (i = 0; i < 3; i++) {
        s8* a0 = (u8*)&background_objects[i];
        s32 v1 = sizeof(struct X4_BackgroundObj) - 1;
        do {
            *a0++ = fill;
        } while (v1-- != 0);
        background_objects[i].unk2 = i;
    }
}

#include "common.h"

extern s8 D_800950A0[];

s8* func_8002C32C(void) {
    s8* p;
    s8* q;
    s32 i;

    for (p = D_800950A0; p < D_800950A0 + 0x1400; p += 0xA0) {
        if (*p == 0) {
            q = p;
            i = 0x9F;
            do {
                *q++ = 0;
                i--;
            } while (i != -1);
            *(s32*)(p + 0x50) = 0;
            *(s32*)(p + 0x54) = 0;
            *(s32*)(p + 0x68) = 0;
            return p;
        }
    }
    return 0;
}
