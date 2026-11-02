#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002ABA8();
void func_8003963C(void* arg0);
void func_8003A980(void* arg0);
void func_8003C4EC(struct X4_PlayerObj* self);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
M2C_UNK func_8003F3DC(void*); /* extern */
extern s8 D_800970FC;
extern s8 D_8009711A;
#include "mmx6/state.h"
extern s32 D_800C1220[];
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEEC;

#define ENG_98 M2C_FIELD(e, s32*, 0x98)

void func_80039228(void* arg0) {
    s8* p;
    s32 i;
    s32 v;
    s16 lim;
    s16 cur;
    s16* q;
    s32 best;
    s16 m;

    if (M2C_FIELD(arg0, s8*, 5) == 0) {
        return;
    }
top:
    if (M2C_FIELD(arg0, s8*, 5) == 1) {
        return;
    }
    if ((M2C_FIELD(arg0, u8*, 0x70) & 0xC) == 0xC) {
        {
            void* e = &g_playthrough_state;
            ENG_98 += M2C_FIELD(arg0, u8*, 0x5C) & 0x7F;
        }
        M2C_FIELD(arg0, s8*, 0x5C) = -0x80;
    }
    if ((M2C_FIELD(arg0, u8*, 0x70) & 3) == 3) {
        {
            void* e = &g_playthrough_state;
            ENG_98 += M2C_FIELD(arg0, u8*, 0x5C) & 0x7F;
        }
        M2C_FIELD(arg0, s8*, 0x5C) = -0x80;
    }
    if (M2C_FIELD(arg0, s8*, 0x5C) != -0x80 &&
        ((M2C_FIELD(arg0, u8*, 0x89) & 0xC) == 0xC ||
         (M2C_FIELD(arg0, u8*, 0x89) & 3) == 3)) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            D_8009711A = 0;
            if (M2C_FIELD(arg0, s8*, 0xE0) == 1) {
                M2C_FIELD(arg0, s8*, 0xE0) = 0;
                D_800CCEEC = 0;
                func_8002ABA8();
            }
        } else {
            D_8009711A = 0;
        }
        M2C_FIELD(arg0, s8*, 0xE5) = 0x4B;
        {
            u8 b;
            b = M2C_FIELD(arg0, u8*, 0x5C) &= 0x7F;
            if (M2C_FIELD(arg0, s8*, 0xE6) >= b) {
                {
                    void* e = &g_playthrough_state;
                    ENG_98 += b;
                }
            }
        }
        p = (s8*)D_800C1220;
        M2C_FIELD(arg0, u8*, 0x5C) -= M2C_FIELD(arg0, u8*, 0xE6);
        for (i = 0x4F; i >= 0; i--) {
            p[0x76] = 0;
            p[0x72] = 0;
            p += 0xA4;
        }
        if (M2C_FIELD(arg0, s8*, 0x5C) > 0) {
            M2C_FIELD(arg0, u8*, 0x5C) |= 0x80;
            M2C_FIELD(arg0, s8*, 0xCA) = 0;
            M2C_FIELD(arg0, s8*, 0x63) = 1;
            M2C_FIELD(arg0, u8*, 0xA5) = M2C_FIELD(arg0, u8*, 0x15);
            if ((u32)(M2C_FIELD(arg0, u8*, 0xE7) - 1) < 4) {
                M2C_FIELD(arg0, s8*, 0x63) = 4;
            }
            {
                void* e = &g_playthrough_state;
                ENG_98 += M2C_FIELD(arg0, s8*, 0xE6);
            }
        } else {
            M2C_FIELD(arg0, s8*, 0x5C) = -0x80;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x79) != 0 && M2C_FIELD(arg0, s8*, 0x61) == 0 &&
        M2C_FIELD(arg0, s8*, 0x7A) != 1) {
        {
            void* e = &g_playthrough_state;
            ENG_98 += (u8)D_800970FC & 0x7F;
        }
        M2C_FIELD(arg0, s8*, 0x5C) = -0x80;
    }
    if (M2C_FIELD(arg0, s8*, 0x5C) == -0x80) {
        M2C_FIELD(arg0, s8*, 0x5C) = 0;
        D_800CCEEC = 1;
        func_8003A980(arg0);
        func_8003F3DC(arg0);
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x61) != 0) {
        if (M2C_FIELD(arg0, s8*, 0x61) >= 0x3C) {
            M2C_FIELD(arg0, s8*, 0x61) = M2C_FIELD(arg0, u8*, 0x61) - 1;
        } else if (!(M2C_FIELD(arg0, s32*, 0xEC) & 0x400) ||
                   (D_80097420.frame_counter & 1)) {
            if ((M2C_FIELD(arg0, s8*, 0x61) = M2C_FIELD(arg0, u8*, 0x61) - 1) ==
                0) {
                M2C_FIELD(arg0, s8*, 0xA4) = 0;
                func_8003C4EC(arg0);
            }
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x5C) > 0) {
        return;
    }
    func_8003963C(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        lim = M2C_FIELD(arg0, s16*, 0x14A);
        v = lim / 8;
        M2C_FIELD(arg0, s16*, 0xA8) += v;
        if (lim < M2C_FIELD(arg0, s16*, 0xA8) ||
            lim - M2C_FIELD(arg0, s16*, 0xA8) < v) {
            M2C_FIELD(arg0, s16*, 0xA8) = M2C_FIELD(arg0, s16*, 0x14A);
        }
    } else {
        M2C_FIELD(arg0, s16*, 0xB2) += get_weapon_energy_cost(arg0, 5) / 2;
        if (M2C_FIELD(arg0, s16*, 0xB2) >= M2C_FIELD(arg0, s16*, 0x14A)) {
            M2C_FIELD(arg0, s16*, 0xB2) = M2C_FIELD(arg0, s16*, 0x14A);
        }
    }
    best = 0;
    if (M2C_FIELD(arg0, s32*, 0xEC) & 0x800) {
        s16* arr;
        s32 mm;
        u16 ul;
        i = 1;
        arr = &M2C_FIELD(arg0, s16*, 0xA8);
        q = &M2C_FIELD(arg0, s16*, 0xAA);
        mm = M2C_FIELD(arg0, s16*, 0xA8);
        ul = M2C_FIELD(arg0, u16*, 0x14A);
        do {
            cur = *q;
            if (cur < mm) {
                mm = cur;
                best = i;
            }
            i++;
            q++;
        } while (i < 9);
        mm += 0xC;
        if ((s16)ul < mm) {
            mm = (s16)ul;
        }
        {
            s32 o = best * 2;
            *(s16*)((s8*)arr + o) = mm;
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80012D9C(s32);
s32 play_sound(s32 a0, s32 a1, void* arg2);
s32 random_byte();
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CCBC();
M2C_UNK func_8003CDBC();
void func_8003CE30(void* arg0);
extern u8 D_80073C70[];
extern s32 D_80073C78[][4];
extern u8 D_80073CD8[];
extern u8 D_800CCF2F;

void func_8003963C(void* arg0) {
    s32 i;
    s32 f;

    ((void (*)())func_8003CCBC)();
    M2C_FIELD(arg0, u8*, 0x5C) = M2C_FIELD(arg0, u8*, 0x5C) & 0x7F;
    func_80012D9C(1);
    play_sound(3, (random_byte() & 1) ^ 1, arg0);
    play_sound(3, 0x11, arg0);
    if (M2C_FIELD(arg0, s8*, 5) != 0x11) {
        s32 one = 1;
        M2C_FIELD(arg0, s8*, 0xA4) = one;
        M2C_FIELD(arg0, s8*, 0xCF) = one;
        M2C_FIELD(arg0, s8*, 0x84) = 0;
        M2C_FIELD(arg0, s8*, 0x8C) = 0;
        func_8003CDBC(arg0);
        func_8003CE30(arg0);
        i = M2C_FIELD(arg0, s8*, 0x63);
        M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0xA5);
        ((void (*)(void*, s32))func_8003BA04)(arg0, D_80073C70[i]);
        M2C_FIELD(arg0, s32*, 0x20) = D_80073C78[i][0];
        M2C_FIELD(arg0, s32*, 0x28) = D_80073C78[i][1];
        f = 0;
        M2C_FIELD(arg0, s32*, 0x24) = D_80073C78[i][2];
        M2C_FIELD(arg0, s32*, 0x2C) = D_80073C78[i][3];
        if ((M2C_FIELD(arg0, s32*, 0xEC) & 0x200) ||
            (M2C_FIELD(arg0, s8*, 2) != 0 && (D_800CCF2F & 0x20))) {
            f = 1;
        }
        if (f != 0 && ((u32)(i - 1) < 2U || i == 4)) {
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
        }
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
        }
        M2C_FIELD(arg0, u8*, 0x61) = D_80073CD8[i];
        if ((u32)(i - 2) < 2U || i == 5) {
            M2C_FIELD(arg0, s8*, 0x67) = 1;
        }
        M2C_FIELD(arg0, s8*, 5) = 0x11;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

#define F_U16(p, off) (*(u16*)((u8*)(p) + (off)))

s32 func_8002FE30(void*);

s32 func_800397F8(void* arg0, s32 arg1) {
    s32 v;
    s16 a;
    s16 r;

    v = arg1 & 0xFF;
    if (v == 0x2F) {
        F_U16(arg0, 0xE) -= 0x10;
        v = func_8002FE30(arg0);
        if (v == 0 || v == 0x38) {
            F_U16(arg0, 0xE) += 0x20;
            v = func_8002FE30(arg0);
        }
    }
    switch (v) {
    case 0x25 ... 0x2C:
        a = F_U16(arg0, 0xA) & 0xF;
        if (v == 0x26) {
            a |= 0x10;
        }
        if (v == 0x2A) {
            a += 0x10;
        }
        if (v == 0x27) {
            a += 0x20;
        }
        if (v == 0x2B) {
            a += 0x20;
        }
        if (v == 0x28) {
            a += 0x30;
        }
        if (v == 0x2C) {
            a += 0x30;
        }
        if ((u32)v >= 0x29) {
            r = a / 4;
        } else {
            r = 0xF - a / 4;
        }
        break;
    case 0x2D:
        r = 0;
        break;
    default:
        break;
    }
    F_U16(arg0, 0xC) = 0;
    F_U16(arg0, 0xE) = r + *(s16*)((u8*)arg0 + 0xE) - F_U16(arg0, 0x6E);
    return v;
}
#undef F_U16

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
s32 func_8003040C(void*);                   /* extern */
s32 func_800397F8(void*, s32);              /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);      /* extern */
M2C_UNK func_8003CD9C();                    /* extern */

#define PICK(a, v)                                                             \
    switch (v) {                                                               \
    case 0x2D:                                                                 \
        a = 0;                                                                 \
        break;                                                                 \
    case 0x25:                                                                 \
    case 0x26:                                                                 \
    case 0x27:                                                                 \
    case 0x28:                                                                 \
        a = 1;                                                                 \
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {                                 \
            a = 2;                                                             \
        }                                                                      \
        break;                                                                 \
    default:                                                                   \
        a = 2;                                                                 \
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {                                 \
            a = 1;                                                             \
        }                                                                      \
        break;                                                                 \
    }

s32 func_80039984(void* arg0) {
    s32 v;
    s32 a;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, u8*, 0xE3) != 0) {
        if (--M2C_FIELD(arg0, u8*, 0xE3) != 0) {
            return 0;
        }
    }
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 4)) {
        return 0;
    }
    v = func_8003040C(arg0);
    if (v == 0x2E) {
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0 && M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003BA04(arg0, 0x90);
        } else {
            play_sound(0, 0x26, arg0);
            M2C_FIELD(arg0, s8*, 0x8E) = 0;
            func_8003BA04(arg0, 0xA0);
        }
        M2C_FIELD(arg0, s16*, 8) = 0;
        M2C_FIELD(arg0, s16*, 0xC) = 0;
        M2C_FIELD(arg0, s8*, 5) = 0x1B;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, u16*, 0xA) = (M2C_FIELD(arg0, u16*, 0xA) & 0xFFF0) + 8;
        func_8003CD9C(arg0);
        return 1;
    } else {
        if ((u8)(v - 0x25) >= 9) {
            return 0;
        }
        if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
            return 0;
        }
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0 && M2C_FIELD(arg0, s8*, 2) == 0) {
            PICK(a, v);
            func_8003BA04(arg0, a | 0x94);
        } else {
            play_sound(0, 0x26, arg0);
            PICK(a, v);
            func_8003BA04(arg0, a + 0xA3);
            M2C_FIELD(arg0, s8*, 0x8E) = 0;
        }
        M2C_FIELD(arg0, s8*, 5) = 0x1C;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        func_800397F8(arg0, v);
    }
    func_8003CD9C(arg0);
    return 1;
}

#undef PICK
