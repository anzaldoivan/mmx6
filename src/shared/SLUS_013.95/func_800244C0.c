#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
void func_800246B4(void* arg0);
void func_800249D4(void* arg0);
void func_80024CC0(s32 arg0, u8 arg1);
void func_80024F90(void* arg0, s32 arg1);
extern M2C_UNK g_Player;
extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;

#define B8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800244C0(void) {
    u8* p = (u8*)&g_Player;
    struct X4_EngineObj* e = &g_playthrough_state;
    s32 v;
    s32 q;
    s32 a0;

    if (e->unk1F != 0) {
        func_80024F90(p, 0);
        if (B8(p, 2) == 0) {
            func_800246B4(p);
        } else {
            func_800249D4(p);
        }
        if (B8(p, 0x14E) != 0) {
            func_80024CC0(0xA, 0);
        }
        if (S16(p, 0x148) != 0) {
            if (S16(p, 0x148) >= 0x3D) {
                func_80024CC0(0x12, U8(p, 0x144) + 0x1A);
            } else if (D_80097420 & 1) {
                func_80024CC0(0x12, U8(p, 0x144) + 0x1A);
            }
        }
        if (e->enable_boss != 0) {
            struct X4_EngineObj* e2 = &g_playthrough_state;
            s16 n = U8(e2, 0x8F) + 1;
            v = n;
            q = v / 10;
            func_80024CC0(0xE, q + 0x3B);
            func_80024CC0(0xF, v - q * 10 + 0x3B);
            func_80024F90(e->boss_ptr, 1);
            if (e->unk25 == 0) {
                v = (B8(e, 0x8C) - 0x20) / 2 + 0xA3;
                a0 = 7;
                if (v >= 0xD4) {
                    v = 0xD3;
                }
                goto call;
            }
            if (e->unk25 == 1) {
                v = (B8(e, 0x8C) - 0x20) / 2;
                a0 = 0x10;
                if (v >= 0x31) {
                    v = 0x30;
                }
            call:
                func_80024CC0(a0, v);
                return;
            }
            func_80024CC0(0x11, 0xA2);
        }
    }
}

#undef B8
#undef U8
#undef S16
