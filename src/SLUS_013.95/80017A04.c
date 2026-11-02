// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80017A04);
// clang-format on

/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:clear_vram_rect_ptrs, AGPL-3.0; proven shared with X6 by exact signature fd1585f50292 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_RectPtrPair D_800C11C0[];
extern struct X4_RectPtrPair* D_80097790;

void func_80017A48(void) {
    u32 i;
    struct X4_RectPtrPair* ptr;

    ptr = &D_800C11C0[0];
    D_80097790 = ptr;

    for (i = 0; i < 8; i++) {
        ptr->rect.x = 0;
        ptr->rect.y = 0;
        ptr->rect.w = 0;
        ptr->rect.h = 0;
        ptr->ptr = NULL;
        ptr++;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:load_vram_rect_ptrs, AGPL-3.0; proven shared with X6 by exact signature d1adcd118b38 (see THIRD_PARTY.md). */
#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern struct X4_RectPtrPair D_800C11C0[];
extern struct X4_RectPtrPair* D_80097790;

void func_80017A88(void) {
    struct X4_RectPtrPair* cur;
    for (cur = &D_800C11C0[0]; cur < &D_800C11C0[8]; cur++) {
        if (cur->ptr != NULL) {
            LoadImage(&cur->rect, cur->ptr);
        }
    }
    D_80097790 = &D_800C11C0[0];
}

#include "common.h"
#include "mmx6/x4.h"
s32 func_80018BE0(s32, u8*);
extern struct X4_RectPtrPair* D_80097790;
extern u8 D_800C8868[];
extern u8 D_800C9868[];

void func_80017B04(u8* arg0, s16 arg1, s16 arg2) {
    struct X4_RectPtrPair* p;
    u8* buf;
    s16 n;
    s16 h;
    u32 w;
    s32 base;
    s8 bank;

    base = arg0[0x47];
    if (arg0[0x48] != base) {
        arg0[0x48] = base;
        {
            s32 off = (u8)base;
            base = *(s32*)(arg0 + 0x38);
            bank = arg0[0x49];
            w = *(u32*)(base + off * 4);
        }
        n = w >> 20;
        if (bank == 3) {
            buf = D_800C8868;
        } else {
            buf = D_800C9868 + (bank << 12);
        }
        func_80018BE0(base + (w & 0xFFFFF), buf);
        p = D_80097790;
        do {
            p->rect.x = arg1;
            p->rect.y = arg2;
            p->ptr = (X4_u_long*)buf;
            if (n < 16) {
                p->rect.w = n * 4;
                n = 0;
                p->rect.h = 16;
            } else {
                p->rect.w = 64;
                h = n / 16;
                h *= 16;
                p->rect.h = h;
                arg2 += h;
                n -= h;
                buf += 0x800;
            }
            p++;
        } while (n != 0);
        p->ptr = 0;
        D_80097790 = p;
    }
}

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

extern s32 D_8006E360;
extern u16 D_80097798[];
extern u16 D_8009E1B0[];
extern u8 D_800C4560;

#define SPAD28 (*(s32*)0x1F800028)

void func_80017C40(void) {
    if (D_800C4560 != 0) {
        if (D_800C4560 & 1) {
            LoadImage(&D_8006E360, (M2C_UNK*)SPAD28);
        }
        if (D_800C4560 & 2) {
            LoadImage(&D_8006E360, (M2C_UNK*)D_80097798);
        }
        if (D_800C4560 & 8) {
            LoadImage(&D_8006E360, (M2C_UNK*)D_8009E1B0);
        }
        D_800C4560 = 0;
    }
}

#include "common.h"

extern u16 D_80097798[];
extern u16 D_8009E1B0[];

#define SPAD28 (*(s32*)0x1F800028)

void func_80017CD8(void) {
    __builtin_memcpy(D_80097798, (void*)SPAD28, 0x4000);
    __builtin_memcpy(D_8009E1B0, (void*)SPAD28, 0x4000);
}

/* Adapted from sozud/mmx4 @807a01b src/main/55C4.c:func_800160AC, AGPL-3.0; proven shared with X6 by exact signature 8cc804b315e5 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u16* D_800A21B0;

void func_80017E24(void) {
    u16* src = D_800A21B0;
    u16* dst = SP_BG_TILE_PIXELS;
    s32 count = (u32)((u8*)SP_BG_TILE_ATTRS - (u8*)dst) >> 1;

    while (count > 0) {
        *dst++ = *src++;
        count--;
    }
}

#include "common.h"
#include "psyq/libgpu.h"

#define M2C_UNK s32

extern M2C_UNK D_8006E368;
extern M2C_UNK D_8006E584;

void func_80017E6C(void) {
    LoadImage(&D_8006E584, &D_8006E368);
}

#include "common.h"

#define SCR_WORD (*(s32*)0x1F800000)

void func_80017630(s32, s32, s32, s32, void*);
extern s8 D_800970A2;
extern u8 D_800AF168[];

void func_80017E98(void) {
    s32 var_s0;
    u8* temp_s1;

    temp_s1 = D_800AF168 + SCR_WORD * 0xA000;
    var_s0 = 8;
    if (D_800970A2 == 1) {
        var_s0 = 0x11;
    }
    func_80017630(0, 0x80, 0x78, var_s0, temp_s1);
    func_80017630(0, 0x120, 0x78, var_s0, temp_s1);
}

#include "common.h"
#include "mmx6/x4.h"
extern u16* D_800A21B0;

void func_80017F24(void) {
    u16* src = SP_BG_TILE_PIXELS;
    u16* dst = D_800A21B0;
    s32 count = (u32)((u8*)SP_BG_TILE_ATTRS - (u8*)src) >> 1;

    while (count > 0) {
        *dst++ = *src++;
        count--;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800709F4[];
M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);

#define F17F6C_ENG_SB(off) (*((s8*)&g_playthrough_state + (off)))
#define F17F6C_ENG_B(off) (*((u8*)&g_playthrough_state + (off)))

void func_80017F6C(void) {
    u8 v;

    if (g_playthrough_state.stage == 0xC &&
        (v = 0x1B, g_playthrough_state.substage != 0)) {
        if (F17F6C_ENG_SB(0x31) == 1) {
            v = 0x14;
        }
    } else if (g_playthrough_state.stage == 0) {
        v = 0x15;
        if (F17F6C_ENG_SB(0x26) != 0) {
            v = 0x17;
        }
    } else if (g_playthrough_state.stage >= 0x13) {
        v = 0x18;
        if (F17F6C_ENG_B(0x43B) == 0) {
            v = 0x19;
        } else if (F17F6C_ENG_B(0x43B) == 1) {
            v = 0x17;
        }
    } else {
        v = D_800709F4[g_playthrough_state.stage * 2];
    }
    play_bgm_xa_track(v, D_800709F4[g_playthrough_state.stage * 2 + 1]);
}

#undef F17F6C_ENG_SB
#undef F17F6C_ENG_B
