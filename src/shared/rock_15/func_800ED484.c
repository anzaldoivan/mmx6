#include "common.h"

s32 func_8002D2D4();
extern s8 D_800CCF5C;
extern u8 D_800F6260[];
extern u8 D_800F62E0[];

s32 func_800ED484(void* arg0) {
    s8* obj = arg0;
    s8 state;
    u8* tbl;
    // !FAKE: depin: dropping it breaks the match (129/133)
    register u8 v asm("$4");
    u8 w;

    state = obj[0x88];
    obj[6] = 0;
    if (state == 0) {
        if (D_800CCF5C / 2 >= obj[0x5C]) {
            obj[0x89] = func_8002D2D4() & 0xF;
            obj[0x8A] = 0;
            obj[0x88] = 1;
            v = *(obj[0x89] * 8 + obj[0x8A] + D_800F62E0);
            ((u8*)obj)[0x8A]++;
            goto store;
        }
    } else if (state == 1) {
        if (D_800CCF5C / 2 < obj[0x5C]) {
            obj[0x89] = func_8002D2D4() & 0xF;
            obj[0x8A] = 0;
            obj[0x88] = 0;
            v = *(obj[0x89] * 8 + obj[0x8A] + D_800F6260);
            ((u8*)obj)[0x8A]++;
            goto store;
        }
    }
    switch (obj[0x88]) {
    case 0:
        tbl = D_800F6260;
        w = *(obj[0x8A] + (obj[0x89] << 3) + tbl);
        if (w == 0xE) {
            obj[0x89] = func_8002D2D4() & 0xF;
            obj[0x8A] = 0;
            obj[5] = *(obj[0x89] * 8 + tbl);
        } else {
            obj[5] = w;
        }
        ((u8*)obj)[0x8A]++;
        break;
    case 1:
        tbl = D_800F62E0;
        w = *(obj[0x8A] + (obj[0x89] << 3) + tbl);
        if (w == 0xE) {
            obj[0x89] = func_8002D2D4() & 0xF;
            obj[0x8A] = 0;
            obj[5] = *(obj[0x89] * 8 + tbl);
        } else {
            obj[5] = w;
        }
        ((u8*)obj)[0x8A]++;
        break;
    case -1:
        obj[0x89] = func_8002D2D4() & 0xF;
        obj[0x8A] = 0;
        v = *(obj[0x89] * 8 + obj[0x8A] + D_800F6260);
        ((u8*)obj)[0x8A]++;
        obj[0x88] = 0;
    store:
        obj[5] = v;
        break;
    }
}
