#include "common.h"

void* alloc_sprite_slot();
extern s8 D_80073D30[][8];

void func_8003DB44(s8 arg0) {
    s8(*base)[8];
    s8* tbl;
    u8* obj;
    u32 i;
    s8 v;
    u8 a;
    u8 b;

    base = D_80073D30;
    i = 0;
    a = 0x21;
    tbl = base[arg0];
    b = 0x11;
    do {
        v = *tbl;
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = a;
            obj[1] = b;
            obj[2] = v;
            obj[4] = 0;
            obj[5] = 0;
            obj[6] = 0;
        }
        i++;
        tbl++;
    } while (i < 8);
}
