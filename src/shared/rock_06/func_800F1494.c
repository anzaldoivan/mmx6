#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK animate_object();                    /* extern */
extern M2C_UNK g_Player;

#define SET_STATE(o, s)                                                        \
    {                                                                          \
        M2C_FIELD(o, u8*, 5) = (s);                                            \
        M2C_FIELD(o, u8*, 6) = 0;                                              \
    }

void func_800F1494(void* arg0) {
    s32 f;
    s32 mv;
    s32 g;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        M2C_FIELD(arg0, u8*, 0x7D) = 1;
        M2C_FIELD(arg0, u16*, 0x98) = 0x160;
        ((void (*)(void*, s32))set_animation)(arg0, 0xD);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            void* pl = &g_Player;
            M2C_FIELD(pl, u8*, 0xD8) = 0x3C;
            M2C_FIELD(pl, u8*, 0x6) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x87) = 0;
        play_sound(2, 5, 0);
    }
    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (!(M2C_FIELD(arg0, u16*, 0x8A) & 0x80)) {
            // !FAKE: goto enters the shared flag-clear arm; duplicating the clear store moved bytes (setcc)
            goto clear;
        }
        play_sound(2, 0x25, 0);
        f = 1;
    } else {
        f = 1;
        if (D_800970FC != -0x80) {
        clear:
            f = 0;
        }
    }
    if (f != 0) {
        SET_STATE(arg0, 0xB);
    } else if (M2C_FIELD(arg0, u8*, 0xA8) & 8) {
        SET_STATE(arg0, 5);
    } else if (M2C_FIELD(arg0, u8*, 0x97) & 2) {
        // !FAKE: goto keeps the shared tail block order; inlining or duplicating the tail moved bytes
        goto tail;
    } else if ((g = M2C_FIELD(arg0, u16*, 0x8A)) & 0x80) {
        SET_STATE(arg0, 0xC);
    } else {
        if (g & 0x30) {
            g = 1;
            if (M2C_FIELD(arg0, s8*, 2) != 0) {
                g = M2C_FIELD(arg0, u8*, 0x7E) == 0;
            }
        } else {
            g = 0;
        }
        if (g != 0) {
            SET_STATE(arg0, 0x11);
        } else {
            g = M2C_FIELD(arg0, u16*, 0x88);
            if (g & 2) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
                mv = 1;
            } else if (g & 1) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                mv = 1;
            } else {
                mv = 0;
            }
            if (mv != 0) {
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    M2C_FIELD(arg0, s32*, 0x20) = 0x16000;
                } else {
                    M2C_FIELD(arg0, s32*, 0x20) = -0x16000;
                }
                M2C_FIELD(arg0, s32*, 8) += M2C_FIELD(arg0, s32*, 0x20);
            }
            ((M2C_UNK(*)())animate_object)(arg0, f);
        }
    }
    return;
tail:
    ((void (*)(void*))animate_object)(arg0);
}
