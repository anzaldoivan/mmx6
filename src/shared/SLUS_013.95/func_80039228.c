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
extern s32 D_80097420;
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
        } else if (!(M2C_FIELD(arg0, s32*, 0xEC) & 0x400) || (D_80097420 & 1)) {
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
