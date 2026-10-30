#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
extern struct X4_PlayerObj g_Player;
extern u16 D_800C4570;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800CCF35;

void func_80033500(u8* arg0) {
    s8 old;
    s8 n;
    s32 found;
    s32 i;
    s32 m;
    u8* q;
    u16 j;
    u8* p;
    u8* pl;
    u8* e;

    old = ((s8*)arg0)[0x14];
    switch (D_800C4570) {
    case 0x800:
        arg0[4] = 2;
        arg0[5] = 0;
        break;
    case 0x40:
        *(s32*)(arg0 + 0x30) = 0;
        *(s32*)(arg0 + 0x34) = 0;
        switch (old) {
        case 10:
            e = (u8*)&g_playthrough_state;
            {
                // !FAKE: depin: dropping it breaks the match (177/187)
                register s32 x asm("$3") = g_Player.unk2;
                if ((g_Player.hp & 0x7F) < ((s8*)(e - -x))[0x5B]) {
                    arg0[5] = 3;
                    m = e[0x63] & 0x7F;
                    if (m == 0x20) {
                        *(s32*)(arg0 + 0x30) = 1;
                    }
                }
            }
            break;
        case 11:
            e = (u8*)&g_playthrough_state;
            {
                // !FAKE: depin: dropping it breaks the match (177/187)
                register s32 x asm("$3") = g_Player.unk2;
                if ((g_Player.hp & 0x7F) < ((s8*)(e - -x))[0x5B]) {
                    arg0[5] = 3;
                    if ((e[0x64] & 0x7F) == 0x20) {
                        *(s32*)(arg0 + 0x30) = 1;
                    }
                }
            }
            break;
        case 12:
            i = 0;
            found = 0;
            for (; i < 9; i++) {
                q = (u8*)&g_Player;
                if (*(s16*)((q - -(i * 2)) + 0xA8) < *(s16*)(q + 0x14A)) {
                    found = 1;
                    break;
                }
            }
            if (found != 0) {
                arg0[5] = 4;
                m = D_800CCF35 & 0x7F;
                if (m == 0x20) {
                    *(s32*)(arg0 + 0x34) = 1;
                }
            }
            break;
        }
        break;
    case 0x4000:
        n = 0x10;
        j = 0;
        if (arg0[0x26] == 0) {
        loop:
            j++;
            n--;
            if (j < 4) {
                if ((arg0 + n)[0x16] == 0) {
                    goto loop;
                }
                goto set2;
            }
        } else {
        set2:
            arg0[5] = 2;
        }
        arg0[0x14] = n;
        break;
    case 0x2000:
        p = arg0 + 0x16;
        n = old;
        do {
            n++;
            if (n >= 13) {
                n = old;
                break;
            }
            if (p[n] != 0) {
                break;
            }
        } while (((s8*)arg0)[0x14] != n);
        arg0[0x14] = n;
        break;
    case 0x8000:
        n = old;
        pl = arg0 + 0x16;
        do {
            n--;
            if (n < 10) {
                n = 0;
                arg0[5] = 0;
            }
            if (pl[n] != 0) {
                break;
            }
        } while (((s8*)arg0)[0x14] != n);
        arg0[0x14] = n;
        break;
    }
    if (((s8*)arg0)[0x14] != old) {
        play_sound(0, 0xC, 0);
    }
}
