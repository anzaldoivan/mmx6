#include "common.h"
#define M2C_UNK s32

#include "psyq/libsnd.h"
#include "mmx6/globals.h"
extern s16 D_8006E358[];

// 0x80017008 play_sfx_sequence: stops a lower-priority sequence on the entry's channel, plays the SEQ or SEP and records the channel priority.
// basis: xref play_sound (docs/leads/derived.tsv:8)
// callers: play_sound
s32 play_sfx_sequence(u8 arg0) {
    u8 a, b;
    u32 flag;
    u32 pri;
    s32 row;
    u32 col;
    u8* p;
    s32 slot;
    u8 t;

    b = D_800E155C[1];
    a = D_800E155C[2];
    flag = b >> 7;
    pri = a & 0xF;
    row = b & 0x7F;
    col = a >> 4;
    p = &D_800E25F8[col];
    if (*p != 0xFF) {
        if (SsIsEos(row, *p & 0x1F) != 0) {
            t = *p;
            if (pri < (t >> 5)) {
                return -1;
            }
            if ((t & 0x1F) == 0x1F) {
                SsSeqStop(row, t);
            } else {
                SsSepStop(row, t & 0xF);
            }
        }
    }
    if (arg0 == 2) {
        slot = D_800E155C[3] & 0x1F;
        ((void (*)(s8, s32, s32, s32))SsSepPlay)(row, slot, 1,
                                                 D_8006E358[flag]);
        D_800E25F8[col] = slot | (pri << 5);
    } else {
        SsSeqPlay(row, 1, D_8006E358[flag]);
        D_800E25F8[col] = (pri << 5) | 0x1F;
    }
    return 0;
}
