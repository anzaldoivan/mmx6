#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
extern struct X4_PlayerObj g_Player;
extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;

void func_80033A38(u8* arg0) {
    s32 g;
    s8 k;

    g = D_80097420;
    if (!(g & 1)) {
        k = ((s8*)arg0)[0x14] != 10;
        if (*(s32*)(arg0 + 0x30) != 0) {
            u8* e = (u8*)&g_playthrough_state;
            u8* p;
            s32 v;
            {
                u8* b = e + 0x63;
                p = b + k;
            }
            v = *p & 0x7F;
            if (v != 0) {
                s8 mx;
                k = v - 1;
                *p = k | 0x80;
                k = (g_Player.hp & 0x7F) + 1;
                mx = ((s8*)(e - -g_Player.unk2))[0x5B];
                if (mx < k) {
                    k = mx;
                }
                g_Player.hp = k;
                if (!(g & 3)) {
                    play_sound(0, 0x17, 0);
                }
            } else {
                s8 mx = ((s8*)(e - -g_Player.unk2))[0x5B];
                if (g_Player.hp != mx) {
                    k = (g_Player.hp & 0x7F) + 1;
                    if (mx < k) {
                        k = mx;
                    }
                    g_Player.hp = k;
                    if (!(g & 3)) {
                        play_sound(0, 0x17, 0);
                    }
                } else {
                    arg0[5] = 1;
                    *(s32*)(arg0 + 0x30) = 0;
                    if (k == 0 && ((s8*)e)[0x64] < 0) {
                        e[0x63] = e[0x64];
                        e[0x64] &= 0x80;
                    }
                }
            }
        } else {
            u8* f = (u8*)&g_playthrough_state;
            u8* q;
            s32 w;
            {
                u8* b = f + 0x63;
                q = b + k;
            }
            w = *q & 0x7F;
            if (w != 0) {
                s8 hi;
                s8 h;
                k = w - 1;
                *q = k | 0x80;
                k = (g_Player.hp & 0x7F) + 1;
                h = g_Player.hp & ~0x7F;
                hi = ((s8*)(f - -g_Player.unk2))[0x5B];
                if (hi < k) {
                    k = hi;
                }
                g_Player.hp = k | h;
                if (!(g & 3)) {
                    play_sound(0, 0x17, 0);
                }
            } else {
                arg0[5] = 1;
                if (k == 0 && ((s8*)f)[0x64] < 0) {
                    f[0x63] = f[0x64];
                    f[0x64] &= 0x80;
                }
            }
        }
    }
}
