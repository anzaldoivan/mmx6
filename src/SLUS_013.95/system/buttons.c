#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8006D600[];
extern struct X4_PlayerObj g_Player;

// 0x8003D7AC map_buttons: read input subroutine.
// basis: community tweaks-index.tsv:321
// callers: none known
u16 map_buttons(u16 arg0) {
    u16 result;
    u16 bit;
    u32 i;
    u16* p;
    u16 v;

    result = 0;
    bit = 1;
    i = 0;
    p = D_8006D600;
    do {
        if (*p & arg0) {
            result |= bit;
        }
        bit <<= 1;
        i++;
        p++;
    } while (i < 16);
    if ((result & 3) == 3) {
        result &= 0xFFFC;
    }
    if ((result & 0xC) == 0xC) {
        result &= 0xFFF3;
    }
    if (g_Player.unk2 == 0) {
        v = (result * 2) & 0x20;
        if (result & 0x20) {
            v |= 0x10;
        }
        result &= 0xFFCF;
        result |= v;
    }
    return result;
}
