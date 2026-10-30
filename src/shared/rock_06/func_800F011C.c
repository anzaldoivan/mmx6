#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_8002D230(void*);                /* extern */
extern M2C_UNK g_Player;
extern s8 D_800970FC;

#define SET_STATE(n)                                                           \
    {                                                                          \
        M2C_FIELD(arg0, s8*, 5) = (n);                                         \
        M2C_FIELD(arg0, s8*, 6) = 0;                                           \
        return;                                                                \
    }

void func_800F011C(void* arg0) {
    s32 hit;
    s32 cond;
    s32 v;
    u16 g;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4200;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, u8*, 0x96) = 0x28;
        M2C_FIELD(arg0, u8*, 0x67) = 1;
        if (M2C_FIELD(arg0, u8*, 0x97) & 0x40) {
            if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
                void* pl = &g_Player;
                M2C_FIELD(pl, u8*, 0xD8) = 0x2C;
                M2C_FIELD(pl, u8*, 0x6) = 0;
            }
        }
        set_animation(arg0, 3);
    }
    if (M2C_FIELD(arg0, u8*, 0x97) & 0x40) {
        if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
            if (M2C_FIELD(arg0, u16*, 0x8A) & 0x80) {
                play_sound(2, 0x25, 0);
                hit = 1;
            } else {
                goto clear;
            }
        } else {
            hit = 1;
            if (D_800970FC != -0x80) {
            clear:
                hit = 0;
            }
        }
        if (hit != 0) {
            SET_STATE(0xB);
        }
    }
    if (M2C_FIELD(arg0, u8*, 0xA8) & 8) {
        if (M2C_FIELD(arg0, u8*, 0x97) & 0x40) {
            SET_STATE(5);
        }
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        SET_STATE(0xB);
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        if (M2C_FIELD(arg0, u8*, 0x97) & 0x40) {
            if (M2C_FIELD(arg0, u16*, 0x8A) & 0x30) {
                cond = 1;
                if (M2C_FIELD(arg0, s8*, 2) != 0) {
                    cond = M2C_FIELD(arg0, u8*, 0x7E) == 0;
                }
            } else {
                cond = 0;
            }
            if (cond != 0) {
                SET_STATE(6);
            }
            if (M2C_FIELD(arg0, s8*, 2) != 0 &&
                M2C_FIELD(arg0, u8*, 0x7D) == 0 &&
                (M2C_FIELD(arg0, u16*, 0x8A) & 0x80)) {
                SET_STATE(0xE);
            }
            g = M2C_FIELD(arg0, u16*, 0x88);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            if (g & 2) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
                v = 1;
            } else if (g & 1) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                v = 1;
            } else {
                v = 0;
            }
            if (v != 0) {
                v = M2C_FIELD(arg0, s16*, 0x98) << 8;
                if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                    v = -v;
                }
                M2C_FIELD(arg0, s32*, 0x20) = v;
            }
            if (M2C_FIELD(arg0, s32*, 0x24) < -0x5E000) {
                M2C_FIELD(arg0, s32*, 0x24) = -0x5E000;
            }
            func_8002D230(arg0);
            return;
        }
        func_8002D230(arg0);
    }
}
