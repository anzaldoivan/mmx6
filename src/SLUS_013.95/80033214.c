// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_80033214);
// clang-format on

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

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80026028();
extern u16 D_800C4570;

void func_800337EC(u8* arg0) {
    s8 old;
    s8 i;
    s8 start;
    s32 n;
    u16 pad;
    u8* p;
    u8* self;
    // !FAKE: depin: dropping it breaks the match (43/147)
    register s32 u asm("$4");

    self = arg0;
    pad = D_800C4570;
    old = ((s8*)self)[0x14];
    if (pad & 0x800) {
        self[4] = 2;
        self[5] = 0;
    } else {
        p = self + 0x16;
        for (n = 9; n >= 0; n--) {
        }
        switch (pad) {
        case 0x40: {
            s8 k = ((s8*)self)[0x14];
            if (k == 16) {
                self[4] = 2;
                self[5] = 0;
                *(s32*)(self + 0x38) = 1;
            } else if (k == 14) {
                self[5] = 5;
                self[6] = 0;
                func_80026028(u, p);
            } else if (k == 13) {
                self[4] = 2;
                self[5] = 0;
            } else {
                self[5] = 7;
                self[6] = 0;
            }
        }
            play_sound(0, 0x22, 0);
            break;
        case 0x1000:
            i = 0x17;
            if (self[0x2D] != 0) {
                self[5] = 8;
            } else {
                i = 9;
                if (self[0x1F] == 0) {
                    // !FAKE: depin: dropping it breaks the match (75/147)
                    register u8* q asm("$6") = p;
                    while (--i >= 0) {
                        if (q[i] != 0) {
                            break;
                        }
                    }
                }
                self[5] = 0;
            }
            self[0x14] = i;
            break;
        case 0x2000:
            old = ((s8*)self)[0x14];
            {
                // !FAKE: depin: dropping it breaks the match (110/147)
                register u8* q asm("$6") = p;
                // !FAKE: depin: dropping it breaks the match (93/147)
                register s32 st asm("$5");
                st = old;
                i = st - 0 + old - st;
            next:
                i++;
                if (i >= 0x11) {
                    i = 0x10;
                    if (self[0x26] == 0) {
                        i = 0xF;
                    }
                } else if (st != i) {
                    if (q[i] == 0) {
                        goto next;
                    }
                }
            }
            self[0x14] = i;
            break;
        case 0x8000:
            old = ((s8*)self)[0x14];
            {
                // !FAKE: depin: dropping it breaks the match (110/147)
                register u8* q asm("$6") = p;
                // !FAKE: depin: dropping it breaks the match (117/147)
                register s32 st asm("$5");
                i = old;
                st = old;
            prev:
                i--;
                if (i < 0xD) {
                    i = old;
                }
                if (q[i] == 0) {
                    if (st != i) {
                        goto prev;
                    }
                }
            }
            self[0x14] = i;
            break;
        }
    }
    if (((s8*)self)[0x14] != old) {
        play_sound(0, 0xC, 0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
extern struct X4_PlayerObj g_Player;
#include "mmx6/state.h"
extern struct X4_EngineObj g_playthrough_state;

void func_80033A38(u8* arg0) {
    s32 g;
    s8 k;

    g = D_80097420.frame_counter;
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

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;

void func_80033C24(u8* arg0) {
    s32 flag;
    u32 i;
    s32 v;
    s32 w;

    if (!(D_80097420.frame_counter & 1)) {
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
                u8* e = (u8*)&g_playthrough_state;
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
            u8* h = (u8*)&g_playthrough_state;
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
                    u8* e = (u8*)&g_playthrough_state;
                    v = e[0x65];
                    w = v & 0x7F;
                    if (w != 0) {
                        w--;
                    }
                    v = D_80097420.frame_counter & 3;
                    e[0x65] = w;
                    if (!v) {
                        play_sound(0, 0x17, 0);
                    }
                }
                } else {
                    // !FAKE: depin: dropping it breaks the match (117/119)
                    register u8* e asm("$4") = (u8*)&g_playthrough_state;
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

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800122A4();
M2C_UNK func_800139A0(s8);
M2C_UNK func_800139F4(M2C_UNK);
void func_800210E8();
M2C_UNK func_80025FB0();
M2C_UNK func_80026028();
void func_8002ACA8(); /* extern; was M2C_UNK (W15 regate of 2ACA8) */
s8* func_8002C590(void);
struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK clear_object_slot();

extern u16 D_800739DC[][6];
extern struct X4_PlayerObj g_Player;
extern u8 D_800C4560;
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_QuadObj* D_800E4440[];

void func_80033E00(struct X4_PlayerObj* self) {
    s8* p;
    struct X4_QuadObj* q;
    s32 i;

    switch (self->unk6) {
    case 0:
        func_800139F4(0x20);
        self->unk6++;
        func_80026028();
        break;
    case 1:
        if (D_80097420.transition.active != 0) {
            func_80026028();
        } else {
            self->unk6++;
        }
        break;
    case 2:
        for (i = 0; i < 10; i++) {
            p = func_8002C590();
            if (p != 0) {
                p[0] = 1;
                p[1] = 2;
                p[2] = i;
            }
        }
        for (i = 0; i < 4; i++) {
            D_800E4440[i] = q = alloc_class6_slot();
            if (q != 0) {
                q->active = 1;
                D_800E4440[i]->id = 0xB;
                *(u8*)&D_800E4440[i]->unk36 = 0xFF;
                if (g_Player.unk2 != 0) {
                    D_800E4440[i]->unk34 = 0x1F;
                } else {
                    D_800E4440[i]->unk34 = 0x7C00;
                }
                D_800E4440[i]->bg_offset = -1;
                D_800E4440[i]->x_pos.u.hi = 0;
                D_800E4440[i]->y_pos.u.hi = 0;
                D_800E4440[i]->on_screen = 1;
                D_800E4440[i]->vertices[0].x.u.hi = D_800739DC[i][0];
                D_800E4440[i]->vertices[0].y.u.hi = D_800739DC[i][1];
                D_800E4440[i]->vertices[1].x.u.hi = D_800739DC[i][2];
                D_800E4440[i]->vertices[1].y.u.hi = D_800739DC[i][3];
                D_800E4440[i]->vertices[2].x.u.hi = D_800739DC[i][2];
                D_800E4440[i]->vertices[2].y.u.hi = D_800739DC[i][3];
                D_800E4440[i]->vertices[3].x.u.hi = D_800739DC[i][4];
                D_800E4440[i]->vertices[3].y.u.hi = D_800739DC[i][5];
            }
        }
        func_800139A0(0x20);
        self->unk6++;
        func_800210E8();
        break;
    case 3:
        if (D_80097420.transition.active == 0) {
            self->unk6++;
        }
        func_800210E8();
        D_800C4560 |= 1;
        func_8002ACA8();
        func_80025FB0();
        break;
    case 4: {
        s8* e = (s8*)&g_playthrough_state;
        u8 t = e[0xD1];
        s8 c = e[0xD1];
        if (g_pad1_buttons[2] & 0x1000) {
            if (c >= -15) {
                e[0xD1] = t - 1;
            }
        }
        if (g_pad1_buttons[2] & 0x4000) {
            s8* e = (s8*)&g_playthrough_state;
            if (e[0xD1] < 16) {
                e[0xD1]++;
            }
        }
        if (g_pad1_buttons[2] & 0x8000) {
            s8* e = (s8*)&g_playthrough_state;
            if (e[0xD0] >= -15) {
                e[0xD0]--;
            }
        }
        if (g_pad1_buttons[2] & 0x2000) {
            s8* e = (s8*)&g_playthrough_state;
            if (e[0xD0] < 16) {
                e[0xD0]++;
            }
        }
        if (g_pad1_buttons[2] & 0x40) {
            self->unk6++;
        }
        if (g_pad1_buttons[2] & 0x10) {
            s8* e = (s8*)&g_playthrough_state;
            e[0xD0] = 0;
            e[0xD1] = 0;
        }
        {
            s8* e = (s8*)&g_playthrough_state;
            func_800122A4(e[0xD0], e[0xD1]);
        }
        func_800210E8();
        func_8002ACA8();
        func_80025FB0();
        break;
    }
    case 5:
        if (g_pad1_buttons[0] == 0) {
            self->unk6++;
        }
        func_800210E8();
        func_8002ACA8();
        func_80025FB0();
        break;
    case 6:
        for (i = 0; i < 4; i++) {
            if (D_800E4440[i] != 0) {
                clear_object_slot(D_800E4440[i]);
            }
        }
        {
            s8* e = (s8*)&g_playthrough_state;
            e[1] = 0;
        }
        self->state = 0;
        self->unk5 = 0;
        func_800210E8();
        func_8002ACA8();
        func_80025FB0();
        break;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);

extern struct X4_PlayerObj g_Player;
extern u16 D_800C4570;
extern struct X4_EngineObj g_playthrough_state;

void func_80034288(struct X4_PlayerObj* self) {
    s8 old;
    s8 i;
    u16 n;
    s32 j;
    s32 found;

    old = self->bg_offset;
    switch (D_800C4570) {
    case 0x800:
        self->state = 2;
        self->unk5 = 0;
        break;
    case 0x40: {
        s8* e = (s8*)&g_playthrough_state;
        if (e[0x464] != 0) {
            return;
        }
        switch (((u8*)self)[0x2D]) {
        case 4: {
            struct X4_PlayerObj* pl = &g_Player;
            if ((pl->hp & 0x7F) <
                ((s8*)&g_playthrough_state + pl->unk2)[0x5B]) {
                self->unk5 = 9;
            }
            break;
        }
        case 5: {
            j = 0;
            found = 0;
            for (; j < 9; j++) {
                u8* pl = (u8*)&g_Player;
                if (*(s16*)((u8*)&g_Player + j * 2 + 0xA8) <
                    *(s16*)(pl + 0x14A)) {
                    found = 1;
                    break;
                }
            }
            if (found != 0) {
                self->unk5 = 0xA;
            }
            break;
        }
        default: {
            {
                s8* e2 = (s8*)&g_playthrough_state;
                e2[0x464] = 1;
            }
            play_sound(0, 0x22, 0);
            if (((u8*)self)[0x2D] == 6) {
                u8* pl = (u8*)&g_Player;
                *(s16*)(pl + 0x148) = 0x1E0;
            } else {
                u8* pl = (u8*)&g_Player;
                *(s16*)(pl + 0x148) = 0x12C;
            }
            {
                u8* pl = (u8*)&g_Player;
                *(s32*)(pl + 0x144) = ((u8*)self)[0x2D];
            }
            break;
        }
        }
        break;
    }
    case 0x1000:
        for (i = 9; i >= 0; i--) {
            u8* p = &self->unk16;
            if (p[i] != 0) {
                break;
            }
        }
        self->bg_offset = i;
        self->unk5 = 0;
        break;
    case 0x4000:
        i = 13;
        for (n = 0; n < 4; n++, i++) {
            if (*((u8*)self + i + 0x16) != 0) {
                self->unk5 = 2;
                break;
            }
        }
        self->bg_offset = i;
        break;
    case 0x2000:
        do {
            i = 10;
            for (n = 0; n < 3; n++, i++) {
                u8* p = &self->unk16;
                if (p[i] != 0) {
                    self->unk5 = 1;
                    break;
                }
            }
            if (n == 3) {
                i = self->bg_offset;
                break;
            }
            if (self->bg_offset == i) {
                break;
            }
            {
                u8* q = &self->unk16;
                if (q[i] != 0) {
                    break;
                }
            }
        } while (1);
        self->bg_offset = i;
        break;
    }
    if (self->bg_offset != old) {
        play_sound(0, 0xC, 0);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;

s32 play_sound(s32 a0, s32 a1, void* arg2);

void func_80034574(struct X4_PlayerObj* arg0) {
    s32 hp;
    s8 max;
    s8 v;

    if (!(D_80097420.frame_counter & 1)) {
        struct X4_PlayerObj* pl = &g_Player;
        s8* e = (s8*)&g_playthrough_state;
        max = ((s8*)&g_playthrough_state + pl->unk2)[0x5B];
        hp = pl->hp & 0x7F;
        if (hp != max) {
            v = hp + 1;
            if (max < v) {
                v = max;
            }
            pl->hp = v;
            if (!(D_80097420.frame_counter & 3)) {
                play_sound(0, 0x17, 0);
            }
        } else {
            arg0->unk5 = 8;
            e[0x464] = 1;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
extern struct X4_PlayerObj g_Player;
extern s8 D_800CD334;

void func_80034614(u8* arg0) {
    s32 flag;
    u32 i;

    if (!(D_80097420.frame_counter & 1)) {
        flag = 0;
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
            if (!(D_80097420.frame_counter & 3)) {
                play_sound(0, 0x17, 0);
            }
        } else {
            arg0[5] = 8;
            D_800CD334 = 1;
        }
    }
}
