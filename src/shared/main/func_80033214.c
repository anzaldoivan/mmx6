#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

extern u8 D_8007397C[];
extern struct X4_PlayerObj g_Player;
extern u16 D_800C4570;

void func_80033214(u8* arg0) {
    s8 cur;
    s8 i;
    s32 w;
    s32 n;
    u8 v;
    u16 k;
    u8* p;
    u16 key;

    key = D_800C4570;
    cur = arg0[0x14];
    switch (key) {
    case 0x800:
        arg0[4] = 2;
        arg0[5] = 0;
        break;
    case 0x40:
        if (arg0[0x14] < 10) {
            struct X4_PlayerObj* pl = &g_Player;
            w = D_8007397C[cur];
            pl->weapon = w;
            if (pl->character == 1) {
                if ((s8)w == 2) {
                    pl->weapon = 1;
                } else if ((s8)w == 4) {
                    pl->weapon = 2;
                } else if ((s8)w == 1) {
                    pl->weapon = 3;
                } else if ((s8)w == 7) {
                    pl->weapon = 4;
                } else if ((s8)w == 8) {
                    pl->weapon = 5;
                } else if ((s8)w == 0) {
                    ((u8*)pl)[0xA6] = 0;
                } else {
                    pl->weapon = 0;
                }
            }
            arg0[4] = 2;
            arg0[5] = 0;
        }
        play_sound(0, 0x22, 0);
        break;
    case 0x1000: {
        s32 old;
        u8* q;

        i = cur;
        old = cur;
        do {
            i--;
            if (i < 0) {
                i = 0;
            }
            if ((s8)old == i || i == 0) {
                break;
            }
            q = arg0 + 0x16;
        } while (q[i] == 0);
        arg0[0x14] = i;
        break;
    }
    case 0x4000:
        n = cur + 1;
        for (;;) {
            i = n;
            if (i >= 10) {
                i = 0x17;
                if (arg0[0x2D] != 0) {
                    v = 8;
                    arg0[5] = v;
                    break;
                }
                for (i = 0xD, k = 0; k < 4; k++, i++) {
                    if ((arg0 + i)[0x16] != 0) {
                        v = 2;
                        arg0[5] = v;
                        break;
                    }
                }
                break;
            }
            if ((s8)arg0[0x14] == i || (arg0 + i)[0x16] != 0) {
                break;
            }
            n = i + 1;
        }
        arg0[0x14] = i;
        break;
    case 0x2000: {
        s32 one;
        s32 m;
        u8 t;

        one = 1;
        t = arg0[0x20];
        p = arg0 + 0x16;
        do {
            do {
            } while (0);
            i = 10;
            k = 0;
            if (t != 0) {
                do {
                    arg0[5] = one;
                } while (0);
            } else {
                for (;;) {
                    do {
                    } while (0);
                    m = (i + 1) << 24;
                    k++;
                    i = m >> 24;
                    if (k >= 3) {
                        break;
                    }
                    if (p[i] != 0) {
                        do {
                            arg0[5] = one;
                        } while (0);
                        break;
                    }
                }
            }
            if (k == 3) {
                i = arg0[0x14];
                break;
            }
        } while ((s8)arg0[0x14] != i && p[i] == 0);
        arg0[0x14] = i;
        break;
    }
    }
    if ((s8)arg0[0x14] != cur) {
        play_sound(0, 0xC, 0);
    }
}
