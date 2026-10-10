#include "common.h"
#include "mmx6/psyq_api.h"

s32 func_80028078(s32, s32, u32);
extern u16 D_800F8C08[][2];
extern X4_RECT D_800F981C[];

#define SCR_08 (*(u16(**)[16][16])0x1F800008)
#define TILE(fld, dx, dy)                                                      \
    {                                                                          \
        s32 x, y, v, c, rw;                                                    \
        u16 t;                                                                 \
        x = D_800F8C08[i][0] + (dx);                                           \
        y = D_800F8C08[i][1] + (dy);                                           \
        v = func_80028078(0, x / 256, y / 256) & 0xFF;                         \
        c = (x & 0xF0) / 16;                                                   \
        rw = (y & 0xF0) / 16;                                                  \
        t = SCR_08[v][rw][c] & 0x3FFF;                                         \
        D_800F981C[i].fld = t;                                                 \
    }

void func_800ED4D0(void) {
    s32 i;

    i = 0;
    do {
        TILE(x, 0, 0);
        TILE(y, 16, 0);
        TILE(w, 0, 16);
        TILE(h, 16, 16);
        i++;
    } while (i < 8);
}
