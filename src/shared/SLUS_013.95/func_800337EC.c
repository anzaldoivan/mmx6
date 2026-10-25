#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80026028();
extern u16 D_800C4570;

void func_800337EC(u8* arg0) {
    s8 old;
    s8 i;
    s8 start;
    s32 n;
    u16 pad;
    u8* p;
    u8* self;
    // !FAKE: depin: dropping it breaks the match (43/147)
    register s32 u asm("$4");

    self = arg0;
    pad = D_800C4570;
    old = ((s8*)self)[0x14];
    if (pad & 0x800) {
        self[4] = 2;
        self[5] = 0;
    } else {
        p = self + 0x16;
        for (n = 9; n >= 0; n--) {
        }
        switch (pad) {
        case 0x40: {
            s8 k = ((s8*)self)[0x14];
            if (k == 16) {
                self[4] = 2;
                self[5] = 0;
                *(s32*)(self + 0x38) = 1;
            } else if (k == 14) {
                self[5] = 5;
                self[6] = 0;
                func_80026028(u, p);
            } else if (k == 13) {
                self[4] = 2;
                self[5] = 0;
            } else {
                self[5] = 7;
                self[6] = 0;
            }
        }
            func_80016C48(0, 0x22, 0);
            break;
        case 0x1000:
            i = 0x17;
            if (self[0x2D] != 0) {
                self[5] = 8;
            } else {
                i = 9;
                if (self[0x1F] == 0) {
                    // !FAKE: depin: dropping it breaks the match (75/147)
                    register u8* q asm("$6") = p;
                    while (--i >= 0) {
                        if (q[i] != 0) {
                            break;
                        }
                    }
                }
                self[5] = 0;
            }
            self[0x14] = i;
            break;
        case 0x2000:
            old = ((s8*)self)[0x14];
            {
                // !FAKE: depin: dropping it breaks the match (110/147)
                register u8* q asm("$6") = p;
                // !FAKE: depin: dropping it breaks the match (93/147)
                register s32 st asm("$5");
                st = old;
                i = st - 0 + old - st;
            next:
                i++;
                if (i >= 0x11) {
                    i = 0x10;
                    if (self[0x26] == 0) {
                        i = 0xF;
                    }
                } else if (st != i) {
                    if (q[i] == 0) {
                        goto next;
                    }
                }
            }
            self[0x14] = i;
            break;
        case 0x8000:
            old = ((s8*)self)[0x14];
            {
                // !FAKE: depin: dropping it breaks the match (110/147)
                register u8* q asm("$6") = p;
                // !FAKE: depin: dropping it breaks the match (117/147)
                register s32 st asm("$5");
                i = old;
                st = old;
            prev:
                i--;
                if (i < 0xD) {
                    i = old;
                }
                if (q[i] == 0) {
                    if (st != i) {
                        goto prev;
                    }
                }
            }
            self[0x14] = i;
            break;
        }
    }
    if (((s8*)self)[0x14] != old) {
        func_80016C48(0, 0xC, 0);
    }
}
