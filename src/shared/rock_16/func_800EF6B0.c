#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
s32 get_reploid_status();
extern s32 D_8006D674[];
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEFB;
extern s32 D_800F0E74[];
extern u16 D_800F1668[];
extern u16 D_800F1680[][2];
extern u16 D_800F1688[][2];

#define F6B0_S8(o) (*(s8*)((s8*)arg0 + (o)))
#define F6B0_U8(o) (*(u8*)((s8*)arg0 + (o)))
#define F6B0_S16(o) (*(s16*)((s8*)arg0 + (o)))
#define F6B0_U16(o) (*(u16*)((s8*)arg0 + (o)))
#define F6B0_PTR(o) (*(void**)((s8*)arg0 + (o)))
#define F6B0_SCRATCH (*(u8**)0x1F800020)
#define F6B0_ENG2B (g_playthrough_state.character_state.bytes[5])

void func_800EF6B0(void* arg0) {
    u8* p;
    u8* q;
    u8* q2;
    s8 v;
    u8 u;
    s32 r;
    s32 w;
    s32 i;

    F6B0_S16(0x40) = 0x1800;
    p = F6B0_SCRATCH;
    v = F6B0_S8(2);
    F6B0_PTR(0x3C) = p + *(s32*)(p + 8);
    F6B0_S16(0x42) = 0x788E;
    F6B0_PTR(0x30) = D_800F1668;
    u = F6B0_U8(2);
    if (v < 2) {
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, v, 0);
        F6B0_U16(0xA) = D_800F1680[F6B0_S8(2)][0];
        F6B0_U16(0xE) = D_800F1680[F6B0_S8(2)][1];
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 0;
    } else if (v < 0x12) {
        F6B0_S16(0x40) = 0x1800;
        F6B0_S16(0x42) = 0x7882;
        q = F6B0_SCRATCH;
        F6B0_PTR(0x3C) = q + *(s32*)(q + 0x10);
        F6B0_S8(2) = u - 2;
        if (get_reploid_status(F6B0_ENG2B * 16 + F6B0_S8(2)) >= 2) {
            F6B0_S8(0x47) = F6B0_U8(2) + F6B0_ENG2B * 16;
        } else {
            F6B0_S8(3) = 0;
        }
        F6B0_U16(0xA) = D_800F1688[F6B0_S8(2)][0] + 0x20;
        F6B0_U16(0xE) = D_800F1688[F6B0_S8(2)][1];
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 1;
    } else if (v < 0x22) {
        F6B0_S8(2) = u - 0x12;
        ((void (*)(void*, s32, s32))set_animation_frame)(
            arg0, 2, get_reploid_status(D_800CCEFB * 16 + F6B0_S8(2), u));
        F6B0_U16(0xA) = D_800F1688[F6B0_S8(2)][0] + 0x59;
        F6B0_U16(0xE) = D_800F1688[F6B0_S8(2)][1];
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 2;
    } else if (v < 0x32) {
        q2 = F6B0_SCRATCH;
        F6B0_PTR(0x3C) = q2 + *(s32*)(q2 + 0xC);
        F6B0_S16(0x42) = 0x78C2;
        F6B0_S8(2) = u - 0x22;
        r = get_reploid_status(F6B0_ENG2B * 16 + F6B0_S8(2));
        if (r == 2 && (w = D_8006D674[F6B0_ENG2B * 16 + F6B0_S8(2)]) != 0) {
            if (w == 1) {
                i = 0x18;
                r = 0;
            } else if (w == r) {
                i = 0x19;
                r = 0;
            } else {
                for (i = 0; i < 0x18; i++) {
                    if (D_800F0E74[i] == w) {
                        goto found;
                    }
                }
                i = 0;
            }
        found:
            ((void (*)(void*, s32, s32))set_animation_frame)(arg0, 3, i);
        } else {
            F6B0_S8(3) = 0;
        }
        F6B0_U16(0xA) = D_800F1688[F6B0_S8(2)][0] + 0xA8;
        F6B0_U16(0xE) = D_800F1688[F6B0_S8(2)][1];
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 3;
    } else if (v < 0x34) {
        F6B0_S8(2) = u - 0x32;
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 4;
    } else if (v < 0x36) {
        F6B0_S8(2) = u - 0x34;
        if (F6B0_S8(2) != 0) {
            F6B0_S16(0x42) = 0x780D;
            F6B0_PTR(0x3C) = F6B0_SCRATCH + *(s32*)F6B0_SCRATCH;
        }
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 5;
    } else if (v < 0x39) {
        F6B0_S8(2) = u - 0x36;
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 6;
    } else if (v < 0x3C) {
        F6B0_S8(2) = u - 0x39;
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 7;
    } else if (v < 0x3F) {
        F6B0_S8(2) = u - 0x3C;
        F6B0_U8(0x16) = 3;
        F6B0_U8(5) = 8;
    } else if (v == 0x3F) {
        F6B0_S16(0x42) = 0x788F;
        F6B0_U8(0x16) = 7;
        F6B0_U8(0x47) = 0xCF;
        F6B0_U8(5) = 9;
    }
    F6B0_S8(0x14) = 1;
    F6B0_U8(4) = F6B0_U8(4) + 1;
}

#undef F6B0_S8
#undef F6B0_U8
#undef F6B0_S16
#undef F6B0_U16
#undef F6B0_PTR
#undef F6B0_SCRATCH
#undef F6B0_ENG2B
