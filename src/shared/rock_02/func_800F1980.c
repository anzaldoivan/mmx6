#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK silence_sound(M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_8007523C;
extern M2C_UNK D_800752DC;
extern M2C_UNK D_8007537C;
extern M2C_UNK g_Player;
extern s8 D_8009711A;
extern u8 D_80097187;
extern void (*D_800FB850[])(void*);

#define SPAD (*(u8**)0x1F80004C)

void func_800F1980(void* arg0) {
    s32 v;
    s8 st;
    u8 c;
    u8* p;
    u8* q;
    u8* r;
    s32 t;
    s32 n;

    v = check_enemy_hits(arg0);
    if (v < 0) {
        silence_sound(0xFF, 0);
        play_sound(2, 0x14, arg0);
        play_sound(2, 0x3D, arg0);
        play_sound(2, 0x21, arg0);
        D_8009711A = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    st = M2C_FIELD(arg0, s8*, 5);
    if (st == 0xC) {
        c = SPAD[0x8B];
        if (c == 0) {
            if (v != 0 && v != 0x7F) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
                if ((u32)(v - 0x19) < 2U) {
                    SPAD[0x8B] = 2;
                } else {
                    SPAD[0x8B] = 0x3C;
                }
            }
        } else {
            t = c - 1;
            SPAD[0x8B] = t;
            if (!(t & 0xFF)) {
                if (D_80097187 == 2) {
                    M2C_FIELD(arg0, void**, 0x58) = &D_8007537C;
                } else {
                    M2C_FIELD(arg0, void**, 0x58) = &D_800752DC;
                }
                M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
            } else if (!(SPAD[0x8B] & 3)) {
                M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
            } else {
                M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
            }
        }
    } else if (v != 0x7F) {
        if (st == 8) {
            if (M2C_FIELD(arg0, s8*, 6) == 0) {
                q = (u8*)&g_Player;
                if (M2C_FIELD(q, s8*, 2) != 0) {
                    if (v != 0) {
                        play_sound(2, 0x3D, arg0);
                        ((void (*)(void*, s32))set_animation)(arg0, 4);
                        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                        M2C_FIELD(arg0, s8*, 5) = 8;
                        M2C_FIELD(arg0, s8*, 6) = 1;
                        SPAD[0x8B] = 0x1E;
                    }
                } else if (q[0xE7] == 2) {
                    if ((u32)(v - 0x33) < 2U || v == 0x2F) {
                        play_sound(2, 0x3D, arg0);
                        ((void (*)(void*, s32))set_animation)(arg0, 4);
                        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                        M2C_FIELD(arg0, s8*, 5) = 8;
                        M2C_FIELD(arg0, s8*, 6) = 1;
                        SPAD[0x8B] = 0x64;
                    }
                } else if (v == 2 || v == 4 || v == 5 || v == 6 || v == 7 ||
                           v == 8 || v == 9 || v == 0xB || v == 0xC ||
                           v == 0xD || v == 0xE || v == 0xF || v == 0x10 ||
                           v == 0x11 || v == 0x12 || v == 0x36 || v == 0x2E ||
                           v == 0x35) {
                    play_sound(2, 0x3D, arg0);
                    ((void (*)(void*, s32))set_animation)(arg0, 4);
                    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                    M2C_FIELD(arg0, s8*, 5) = 8;
                    M2C_FIELD(arg0, s8*, 6) = 1;
                    SPAD[0x8B] = 0x64;
                }
            }
        } else if (st != 0xC) {
            if ((u32)(v - 0x13) < 3U || v == 0x2F || v == 0x39 || v == 0x2C ||
                v == 0x22 || v == 0x23 || v == 0x24 || v == 0x25 || v == 0x2B ||
                v == 0x2D) {
                play_sound(2, 0x3D, arg0);
                play_sound(2, 0x14, arg0);
                SPAD[0x86] = M2C_FIELD(arg0, u8*, 5);
                SPAD[0x87] = M2C_FIELD(arg0, u8*, 6);
                SPAD[0x8B] = 0;
                if (D_80097187 == 2) {
                    M2C_FIELD(arg0, void**, 0x58) = &D_8007537C;
                } else {
                    M2C_FIELD(arg0, void**, 0x58) = &D_800752DC;
                }
                M2C_FIELD(arg0, s8*, 5) = 8;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        }
    }
    D_800FB850[M2C_FIELD(arg0, s8*, 5)](arg0);
    ((void (*)(void*))func_80030ECC)(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 5) != 2) {
            M2C_FIELD(arg0, s32*, 0x90) += 1;
        }
        p = (u8*)&g_Player;
        if (M2C_FIELD(p, s8*, 0x5C) == -0x80) {
            M2C_FIELD(p, s8*, 0x5C) = 1;
        }
        n = 9;
        if (M2C_FIELD(arg0, s8*, 5) != n) {
            if ((M2C_FIELD(p, s8*, 0x5C) & 0x7F) < 2) {
                func_8003D308(0x14, p[0x15]);
                M2C_FIELD(p, s8*, 0x5C) = 1;
                goto block_73;
            }
            if (M2C_FIELD(arg0, s32*, 0x90) >= 0x385) {
                func_8003D308(0x14, p[0x15]);
            block_73:
                M2C_FIELD(arg0, s8*, 5) = n;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        }
    }
    if (M2C_FIELD(SPAD, s8*, 0x89) != 0) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        r = SPAD;
        if (--M2C_FIELD(r, s8*, 0x89) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007523C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        } else if (!(SPAD[0x89] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    if (M2C_FIELD(arg0, s8*, 5) != 2) {
        func_8002CCB0(arg0, 0x80, 0x80);
    }
}
