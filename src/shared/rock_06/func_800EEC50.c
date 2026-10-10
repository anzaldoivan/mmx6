#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_80017A04();                        /* extern */
extern M2C_UNK D_800970A0;
extern s8 D_800970FC;

#define SET(k)                                                                 \
    {                                                                          \
        M2C_FIELD(arg0, u8*, 5) = (k);                                         \
        M2C_FIELD(arg0, u8*, 6) = 0;                                           \
        return;                                                                \
    }

#define SETC(k)                                                                \
    {                                                                          \
        M2C_FIELD(arg0, u8*, 5) = (k);                                         \
        M2C_FIELD(arg0, u8*, 6) = 0;                                           \
        goto call;                                                             \
    }

void func_800EEC50(void* arg0) {
    s32 h;
    s32 v;
    s32 t;
    u16 m;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s16*, 0x98) = 0x160;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            u8* pl = (u8*)&D_800970A0;
            M2C_FIELD(pl, u8*, 0xD8) = 0x29;
            M2C_FIELD(pl, u8*, 6) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x87) = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x94) == 2) {
        SET(0xD);
    }
    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x80) {
            func_80016C48(2, 0x25, 0);
            h = 1;
            goto h_done;
        }
    } else if (D_800970FC == -0x80) {
        h = 1;
        goto h_done;
    }
    h = 0;
h_done:
    if (h) {
        SET(0xB);
    }
    if (!(M2C_FIELD(arg0, u8*, 0xA8) & 8)) {
        SET(0xC);
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
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
            SETC(2);
        }
        m = M2C_FIELD(arg0, u16*, 0x8A);
        if (m & 0x80) {
            SETC(4);
        }
        if (m & 0x30) {
            t = 1;
            if (M2C_FIELD(arg0, s8*, 2) != 0) {
                t = M2C_FIELD(arg0, u8*, 0x7E) == 0;
            }
        } else {
            t = 0;
        }
        if (t) {
            SETC(3);
        }
    call:
        ((void (*)(void*))func_80017A04)(arg0);
    } else {
        ((void (*)(void*))func_80017A04)(arg0);
    }
}
#undef SET
#undef SETC
