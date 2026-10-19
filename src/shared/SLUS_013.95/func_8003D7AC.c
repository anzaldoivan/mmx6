#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8006D600[];
extern struct X4_PlayerObj D_800970A0;

u16 func_8003D7AC(u16 arg0) {
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
    if (D_800970A0.unk2 == 0) {
        v = (result * 2) & 0x20;
        if (result & 0x20) {
            v |= 0x10;
        }
        result &= 0xFFCF;
        result |= v;
    }
    return result;
}
