#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
M2C_UNK reset_level();
void* alloc_sprite_slot();
void func_800ED45C();
#include "mmx6/state.h"
extern u16 g_pad1_buttons[];
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800F366C[];

void func_800EBB30(u8* arg0) {
    s32 ret;
    s32 done;
    u8 old;
    u8 i;
    u8* obj;

    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        return;
    }
    old = D_80097420.transition.selection;
    if (g_pad1_buttons[2] & 0x1000) {
        if (old == 0) {
            for (i = 0; i < 7; i++) {
                D_800E2F90.y_pos.val += 0x3BC;
            }
            D_80097420.transition.selection = 7;
        } else {
            D_800E2F90.y_pos.val -= 0x3BC;
            D_80097420.transition.selection = old - 1;
        }
        func_800ED45C();
    }
    if (g_pad1_buttons[2] & 0x4000) {
        if ((u8)D_80097420.transition.selection == 7) {
            for (i = 0; i < 7; i++) {
                D_800E2F90.y_pos.val -= 0x3BC;
            }
            D_80097420.transition.selection = 0;
        } else {
            D_80097420.transition.selection =
                D_80097420.transition.selection + 1;
            D_800E2F90.y_pos.val += 0x3BC;
        }
        func_800ED45C();
    }
    if ((u8)D_80097420.transition.selection != old) {
        play_sound(0, 0xC, 0);
    }
    if (g_pad1_buttons[2] & 0x10) {
        play_sound(0, 0x22, 0);
        ((void (*)())reset_level)();
        arg0[1] = 6;
        arg0[2] = 6;
        arg0[3] = 0;
        return;
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        D_800E2F90.unk7 = D_80097420.transition.selection;
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2D;
            ((s8*)obj)[2] = -0x41;
        }
        *(u8**)(D_800F366C + 0x1290) = obj;
        D_800E2F90.x_pos.bytes[2] = 3;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[3] = 9;
        arg0[1] = arg0[1] + 1;
        func_800ED45C();
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
void* alloc_sprite_slot();
void func_800ED45C();
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800F366C[];

void func_800EBD9C(u8* arg0) {
    s32 ret;
    s32 done;
    s32 n;
    u8* p;
    u8* obj;
    u8 idx;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        return;
    }
    if (g_pad1_buttons[2] & 0xA000) {
        play_sound(0, 0xC, 0);
        g_playthrough_state.unkA ^= 1;
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        p = *(u8**)(D_800F366C + 0x1290);
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (g_playthrough_state.unkA == 0) {
            idx = *(u8*)D_800E2F90.y_pos.val;
            if (idx != 0xFF) {
                obj = alloc_sprite_slot(idx);
                if (obj != 0) {
                    obj[0] = 1;
                    obj[1] = 0x2D;
                    ((s8*)obj)[2] = -0x41;
                }
                *(u8**)(D_800F366C + 0x1290) = obj;
                D_800E2F90.x_pos.bytes[2] = 3;
                *(s16*)(arg0 + 0xA) = 1;
                arg0[1] = arg0[1] + 1;
                func_800ED45C();
                arg0[3] = 0xA;
                return;
            }
            D_800E2F90.x_pos.bytes[2] = 3;
            arg0[3] = 0xB;
            arg0[1] = arg0[1] + 2;
            return;
        }
        arg0[3] = 8;
        arg0[1] = arg0[1] - 1;
        func_800ED45C();
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
void func_800ED45C();
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800F366C[];

void func_800EBF8C(u8* arg0) {
    s32 ret;
    s32 done;
    s32 n;
    u8* p;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        return;
    }
    if (g_pad1_buttons[2] & 0xA000) {
        play_sound(0, 0xC, 0);
        g_playthrough_state.unkA ^= 1;
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        p = *(u8**)(D_800F366C + 0x1290);
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (g_playthrough_state.unkA == 0) {
            D_800E2F90.x_pos.bytes[2] = 3;
            arg0[3] = 0xB;
            arg0[1] = arg0[1] + 1;
            return;
        }
        arg0[3] = 8;
        arg0[1] = arg0[1] - 2;
        func_800ED45C();
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_8001C5EC(u8);
void func_800ED45C();
void func_800EE19C(void);
void func_800EE878(struct X4_MiscObj*);
extern u8 D_8006D620;
extern struct X4_MiscObj D_800E2F90;

void func_800EC104(u8* arg0) {
    s32 ret;
    s32 done;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        return;
    }
    func_800EE19C();
    func_800EE878(&D_800E2F90);
    if ((s8)arg0[1] != 0x15) {
        D_8006D620 = D_80097420.transition.selection;
        arg0[3] = 0xC;
        arg0[1] = arg0[1] + 1;
        func_800ED45C();
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK reset_level();
void func_800F02A0(u8, s8, s32, s16);
M2C_UNK func_800F0324(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
extern u16 g_pad1_buttons[];

void func_800EC1F4(u8* arg0) {
    s32 one;
    u8 v;
    u8 t;
    s32 r;

    one = 1;
    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        t = D_80097420.transition.selection;
        if (t == 0) {
            D_80097420.transition.selection = one;
        } else {
            D_80097420.transition.selection = t - 1;
        }
    } else if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        t = D_80097420.transition.selection;
        if (t == one) {
            D_80097420.transition.selection = 0;
        } else {
            D_80097420.transition.selection = t + 1;
        }
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        ((void (*)())reset_level)();
        v = D_80097420.transition.selection;
        switch (v) {
        case 0:
            func_800139F4(8);
            r = 3;
            arg0[2] = r;
            arg0[3] = 0;
            break;
        case 1:
            func_800F02A0(0x95, 1, 0x11C, 0x40);
            func_800F0324(0xBC, 1, 0x16C, 0x80, 0);
            func_800F0324(0xC1, 1, 0x16C, 0xA0, v);
            func_800F02A0(0xB9, 1, 0, 0);
            D_80097420.transition.selection = v;
            r = 2;
            arg0[2] = r;
            arg0[3] = 0;
            break;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK reset_level();
extern u16 g_pad1_buttons[];

void func_800EC378(u8* arg0) {
    s32 one;
    u8 t;

    one = 1;
    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        t = D_80097420.transition.selection;
        if (t == 0) {
            D_80097420.transition.selection = one;
        } else {
            D_80097420.transition.selection = t - 1;
        }
    } else if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        t = D_80097420.transition.selection;
        if (t == one) {
            D_80097420.transition.selection = 0;
        } else {
            D_80097420.transition.selection = t + 1;
        }
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        ((void (*)())reset_level)();
        switch (D_80097420.transition.selection) {
        case 0:
            func_800139F4(8);
            {
                // !FAKE: depin: dropping it breaks the match (72/75)
                register s32 three asm("$2") = 3;
                // !FAKE: depin: dropping it breaks the match (72/75)
                register s32 k1 asm("$3") = 1;

                arg0[2] = three;
                arg0[3] = k1;
            }
            break;
        case 1:
            arg0[2] = 0;
            break;
        }
    }
}

#define func_800EB15C func_800EC4A4
#define D_800F0B30 D_800F3BEC
#include "../shared/rock_18/func_800EB15C.c"
#undef func_800EB15C
#undef D_800F0B30

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800ECB00);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800ECF10);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800ED45C);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8006D600[];
extern s32 D_80070CC4[];
extern s8 D_800CC869;
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_MiscObj D_800E2F90;

#define DST (*(u8**)((u8*)&D_800E2F90 + 0xC))
#define MISC ((u8*)&D_800E2F90)
#define ENG ((u8*)&g_playthrough_state)

void func_800EE19C(void) {
    u8* dst;
    s32 i;
    s32 j;
    u8* q;
    u16 sum;
    u8* d84;
    u8* dCE;
    u8* d390;
    u8* dm;
    s32* w;

    {
        u8* m = MISC;
        dst = *(u8**)(m + 0xC);
    }
    {
        u8* src = ENG;
        dst[0] = 0;
        dst[1] = src[0x66];
        dst[2] = src[0x68];
        dst[3] = D_800CC869;
        *(s32*)(dst + 4) = *(s32*)(src + 0x70);
        for (i = 0; i < 2; i++) {
            ((s32*)(dst + 8))[i] = ((s32*)(src + 0x74))[i];
        }
    }
    {
        u8* src = ENG;
        *(s32*)(dst + 0x10) = *(s32*)(src + 0x6C);
        *(u16*)(dst + 0x14) = *(u16*)(src + 0x6A);
        for (i = 0; i < 16; i++) {
            ((u16*)(dst + 0x16))[i] = D_8006D600[i];
        }
    }
    {
        u8* src = ENG;
        dst[0x38] = src[0x61];
        dst[0x39] = src[0x62];
        dst[0x36] = src[0x5B];
        dst[0x37] = src[0x5C];
        dst[0x3A] = src[0x60];
        dst[0x3B] = src[0x5F];
        dst[0x3C] = src[0x69];
        dst[0x3D] = src[0x8D];
        dst[0x3E] = src[0x8E];
        *(s32*)(dst + 0x40) = *(s32*)(src + 0xCC);
        dst[0x3F] = src[0x43B];
        dst[0xCC] = src[0xC9];
        for (i = 0; i < 16; i++) {
            if (i < 8) {
                u8* d = dst + 0xAE;
                u8* s = src + 0x158;
                s32 o = i;
                *(u8*)(d + o) = *(u8*)(s + o);
            }
            {
                u8* d = dst + 0x44;
                u8* s = src + 0xD8;
                s32 o = i << 2;
                *(s32*)(d + o) = *(s32*)(s + o);
            }
            {
                u8* d = dst + 0xBC;
                u8* s = src + 0x168;
                s32 o = i;
                *(u8*)(d + o) = *(u8*)(s + o);
            }
        }
    }
    d84 = dst + 0x84;
    for (i = 0; i < 21; i++) {
        u8* src = ENG;
        ((u16*)d84)[i] = ((u16*)(src + 0x9E))[i];
    }
    for (i = 0; i < 22; i++) {
        u8* src = ENG;
        for (j = 0; j < 32; j++) {
            dCE = dst + 0xCE;
            dCE[j + (i << 5)] = (src + 0x178)[j + (i << 5)];
        }
    }
    {
        u8* src = ENG;
        dst[0xB6] = src[0xD0];
        dst[0xB7] = src[0xD1];
        *(u16*)(dst + 0xB8) = *(u16*)(src + 0xD2);
        *(u16*)(dst + 0xBA) = *(u16*)(src + 0xD4);
        dst[0xCD] = src[0x438];
        d390 = dst + 0x390;
        for (i = 0; i < 9; i++) {
            ((s32*)d390)[i] = ((s32*)(src + 0x43C))[i];
        }
    }
    {
        u8* src = ENG;
        dst[0x3B4] = src[0x465];
        dst[0x3B5] = src[0x466];
        dst[0x3B6] = src[0x467];
    }
    q = dst;
    dm = dst - 0x3B8;
    sum = 0;
    for (i = 0; i < dst - dm; i++) {
        sum += *q++;
    }
    *(u16*)(dst + 0x3B8) = sum + 0x55;
    {
        u8* m = MISC;
        w = *(s32**)(m + 0xC);
    }
    __builtin_memcpy(D_80070CC4, w, 0x3BC);
}

#undef DST
#undef ENG
#undef MISC
