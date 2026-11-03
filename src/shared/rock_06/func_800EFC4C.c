#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK animate_object();                    /* extern */
extern M2C_UNK g_Player;

void func_800EFC4C(void* arg0) {
    s32 hit;
    s32 cond;
    u16 f;
    s8 st;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        M2C_FIELD(arg0, s16*, 0x98) = 0x160;
        ((void (*)(void*, s32))set_animation)(arg0, 7);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            void* pl = &g_Player;
            M2C_FIELD(pl, u8*, 0xD8) = 0x30;
            M2C_FIELD(pl, u8*, 0x6) = 0;
        }
    }
    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x80) {
            play_sound(2, 0x25, 0);
            hit = 1;
        } else {
            // !FAKE: goto enters the shared flag-clear arm; duplicating the clear store moved bytes (setcc)
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
        M2C_FIELD(arg0, s8*, 5) = 0xB;
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            st = 1;
        } else {
            f = M2C_FIELD(arg0, u16*, 0x8A);
            if (f & 0x80) {
                st = 4;
            } else {
                if (f & 0x30) {
                    cond = 1;
                    if (M2C_FIELD(arg0, s8*, 2) != 0) {
                        cond = M2C_FIELD(arg0, u8*, 0x7E) == 0;
                    }
                } else {
                    cond = 0;
                }
                if (cond != 0) {
                    st = 3;
                } else {
                    if (!(M2C_FIELD(arg0, u16*, 0x88) & 3)) {
                        // !FAKE: goto skips st stores; copied call+return moved
                        goto call;
                    }
                    st = 3;
                }
            }
        }
        M2C_FIELD(arg0, s8*, 5) = st;
        M2C_FIELD(arg0, s8*, 6) = 0;
    call:
        ((M2C_UNK(*)())animate_object)(arg0, hit);
    } else {
        ((M2C_UNK(*)())animate_object)(arg0);
    }
}
