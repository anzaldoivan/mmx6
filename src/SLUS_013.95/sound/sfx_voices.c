#include "common.h"
#include "psyq/libspu.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#include "psyq/libsnd.h"
extern struct X4_BackgroundObj background_objects[3];

// 0x80016D34 key_on_sfx_voices: keys on the SPU voices of a sound entry with per-voice priority and pan from the source object's screen x.
// basis: xref play_sound (docs/leads/derived.tsv:7)
// callers: play_sound
s32 key_on_sfx_voices(u8 arg0, u8 arg1, struct X4_AnimatedObj* arg2) {
    u8 buf[0x20];
    s8 fp;
    s16 x;
    s8 bg;
    u8 a, b, c;
    s16 col;
    s16 row;
    u8 slot;
    s32 pri;
    u32 flag;
    s8 n;
    s16 lo;
    s16 hi;
    u8 p26;
    u8 p25;

    if (arg2 != 0) {
        if (arg0 & 0x80) {
            fp = arg2->unk2;
        } else {
            bg = arg2->bg_offset;
            x = arg2->x_pos.i.hi;
            if (bg >= 0) {
                x -= background_objects[bg].x_pos.i.hi;
            }
            fp = x / 10;
            if (fp < 5) {
                fp = 5;
            }
            if (fp >= 0x1C) {
                fp = 0x1B;
            }
        }
    }
    a = D_800E155C[2];
    b = D_800E155C[1];
    c = D_800E155C[3];
    col = a >> 4;
    row = b & 0x7F;
    n = (c & 0x60) >> 5;
    slot = c & 0x1F;
    flag = b >> 7;
    pri = a & 0xF;
    for (; n >= 0; n--, slot++) {
        SsUtGetVagAtr(arg1, row, col, buf);
        lo = buf[2];
        hi = lo;
        if (flag == 0 && arg2 != 0) {
            if (fp < 0x10) {
                lo = (lo >> 4) * fp;
            } else if (fp > 0x10) {
                hi = (lo >> 4) * (0x20 - fp);
            }
        }
        p26 = buf[6];
        p25 = buf[5];
        if (SpuGetKeyStatus(1 << slot) == 0) {
            SsUtKeyOnV(slot, arg1, row, col, p26, p25, hi, lo);
            D_800E25E0[slot] = pri;
        } else {
            if (pri < D_800E25E0[slot]) {
                return -4;
            }
            SsUtKeyOnV(slot, arg1, row, col, p26, p25, hi, lo);
            D_800E25E0[slot] = pri;
        }
        col++;
        if (col >= 0x10) {
            row++;
            col = 0;
        }
    }
    return 0;
}
