#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK silence_sound(M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK animate_object();                    /* extern */
extern M2C_UNK g_Player;

void func_800EF524(void* arg0) {
    s32 h;
    s32 t;
    s32 v;
    s32 r;
    s32 s;
    u16 m;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s16*, 0x98) = 0x160;
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        M2C_FIELD(arg0, u8*, 0x7D) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 4);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            u8* pl = (u8*)&g_Player;
            M2C_FIELD(pl, u8*, 0xD8) = 0x2D;
            M2C_FIELD(pl, u8*, 6) = 0;
        }
        M2C_FIELD(arg0, u8*, 0xA8) |= 8;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            play_sound(2, 0x28, 0);
        } else {
            play_sound(2, 0, 0);
            silence_sound(2, 5);
            play_sound(2, 0, 0);
        }
    }
    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x80) {
            play_sound(2, 0x25, 0);
            h = 1;
            // !FAKE: h flag order; if/else h=0 arms moved bytes
            goto h_done;
        }
    } else if (D_800970FC == -0x80) {
        h = 1;
        // !FAKE: h flag order; if/else h=0 arms moved bytes
        goto h_done;
    }
    h = 0;
h_done:
    if (h) {
        r = 0xB;
        // !FAKE: shared tail order; dup tails moved bytes
        goto set;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        r = 1;
    set:
        M2C_FIELD(arg0, u8*, 5) = r;
        M2C_FIELD(arg0, u8*, 6) = 0;
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        if (!(M2C_FIELD(arg0, u8*, 0xA8) & 8)) {
            s = 0xC;
            // !FAKE: shared tail order; dup tails moved bytes
            goto set2;
        }
        t = 0;
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x30) {
            t = 1;
            if (M2C_FIELD(arg0, s8*, 2) != 0) {
                t = M2C_FIELD(arg0, u8*, 0x7E) == 0;
            }
        }
        if (t) {
            s = 3;
        set2:
            M2C_FIELD(arg0, u8*, 5) = s;
            M2C_FIELD(arg0, u8*, 6) = 0;
            // !FAKE: shared tail order; dup tails moved bytes
            goto call;
        }
    move:
        m = M2C_FIELD(arg0, u16*, 0x88);
        if (m & 2) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            v = 1;
        } else if (m & 1) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            v = 1;
        } else {
            v = 0;
        }
        if (v) {
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s32*, 0x20) = 0x16000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = -0x16000;
            }
            M2C_FIELD(arg0, s32*, 8) += M2C_FIELD(arg0, s32*, 0x20);
        }
    call:
        animate_object(arg0);
        return;
    }
    animate_object(arg0);
}
