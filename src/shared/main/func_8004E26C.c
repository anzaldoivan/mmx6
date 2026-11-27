#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_RideArmorObj D_800CD340;

s32 func_8002DCF4(void*, void*);
void func_8004DDD4(void*, u8);
void func_8004E0A8(u8* arg0, u8 arg1, s32 arg2);
s32 play_sound(s32 a0, s32 a1, void* arg2);

#define F(T, o) (*(T*)((u8*)arg0 + (o)))
#define B(T, b, o) (*(T*)((u8*)(b) + (o)))
#define E(T, o) B(T, e, o)
#define P(T, o) B(T, pl, o)

void func_8004E26C(void* arg0) {
    u8* p;
    u8* pl;

    pl = (u8*)&g_Player;
    if (B(s8, pl, 0xD5) != 0) {
        p = (u8*)&D_800CD340;
        if (B(s8, p, 0x5) == 0) {
            p += 0xB0;
        }
    } else {
        p = pl;
    }
    if (!(B(u8, p, 0x5C) & 0x7F)) {
        return;
    }
    if (func_8002DCF4(arg0, p) == 0) {
        return;
    }
    F(u8, 0x5) = 0;
    switch (F(u8, 0x82)) {
    case 0: {
        u8* e = (u8*)&g_playthrough_state;
        s32 m = 1 << F(s8, 0x2);
        u8* pl;
        u8* q;
        s32 i;
        if (E(s32, 0x6C) & m) {
            break;
        }
        E(s32, 0x6C) |= m;
        pl = (u8*)&g_Player;
        i = P(s8, 0x2);
        q = e + 0x5B;
        q[i] += 2;
        play_sound(0, 0x15, 0);
        break;
    }
    case 1: {
        u8* e = (u8*)&g_playthrough_state;
        s32 m = 0x10000 << (F(s8, 0x2) - 0x10);
        u8* pl;
        u8* q;
        s32 i;
        if (E(s32, 0x6C) & m) {
            break;
        }
        E(s32, 0x6C) |= m;
        pl = (u8*)&g_Player;
        i = P(s8, 0x2);
        q = e + 0x61;
        q[i] += 2;
        ((void (*)(s32, s32, void*))play_sound)(0, 0x15, 0);
        break;
    }
    case 2: {
        u8* pl = (u8*)&g_Player;
        if (P(s32, 0xEC) & 0x40) {
            func_8004E0A8(arg0, 5, 2);
        } else {
            func_8004E0A8(arg0, 4, 1);
        }
        return;
    }
    case 3: {
        u8* pl = (u8*)&g_Player;
        if (P(s32, 0xEC) & 0x40) {
            func_8004E0A8(arg0, 0x14, 3);
        } else {
            func_8004E0A8(arg0, 0x10, 2);
        }
        return;
    }
    case 4: {
        S5B* e = (S5B*)&g_playthrough_state;
        u8* pl = (u8*)&g_Player;
        func_8004E0A8(arg0, e->a[P(s8, 0x2)], 4);
        return;
    }
    case 5:
    case 6:
    case 7:
        func_8004DDD4(arg0, F(u8, 0x82));
        break;
    case 8: {
        u8* e = (u8*)&g_playthrough_state;
        if (++E(s8, 0x39) >= 10) {
            E(s8, 0x39) = 9;
        } else {
            play_sound(0, 0x15, 0);
        }
        break;
    }
    case 9: {
        u8* e = (u8*)&g_playthrough_state;
        s32 m = 0x1000 << (F(s8, 0x2) - 0x27);
        u16 h = E(u16, 0x6A);
        if (h & m) {
            return;
        }
        E(u16, 0x6A) = h | m;
        F(u8, 0x4) = 3;
        if (F(s8, 0x2) == 0x27) {
            E(s8, 0x63) = -0x80;
        } else {
            E(s8, 0x64) = -0x80;
        }
        play_sound(0, 0x15, 0);
        return;
    }
    case 10: {
        u8* e = (u8*)&g_playthrough_state;
        if (E(u16, 0x6A) & 0x4000) {
            return;
        }
        E(u16, 0x6A) |= 0x4000;
        F(u8, 0x4) = 3;
        play_sound(0, 0x15, 0);
        E(u8, 0x65) = 0;
        return;
    }
    case 11: {
        u8* e = (u8*)&g_playthrough_state;
        if (E(u16, 0x6A) & 0x8000) {
            return;
        }
        E(u16, 0x6A) |= 0x8000;
        F(u8, 0x4) = 3;
        play_sound(0, 0x15, 0);
        return;
    }
    }
    F(u8, 0x4) = 3;
}
