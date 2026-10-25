#include "common.h"
#include "mmx6/x4.h"

struct X4_MiscObj* func_8002C530(void);
extern struct X4_ObjectHeader D_80097420;
extern u8 D_800FA900[];

#define EB734_FLAGS (*(s32*)&D_80097420)
#define F(p, t, o) (*(t*)((u8*)(p) + (o)))
#define TBL(off) ((u8(*)[2])(D_800FA900 + (off)))

#define SPAWN_HEAD(m, u2)                                                      \
    do {                                                                       \
        F(m, u8, 0x0) = 0x41;                                                  \
        F(m, u8, 0x1) = 7;                                                     \
        F(m, u8, 0x2) = u2;                                                    \
        F(m, u8, 0x15) = F(self, u8, 0x15);                                    \
        F(m, u16, 0x40) = F(self, u16, 0x40);                                  \
        F(m, u16, 0x42) = F(self, u16, 0x42) & 0x7FFF;                         \
        F(m, s32, 0x30) = F(self, s32, 0x30);                                  \
        F(m, s32, 0x3C) = F(self, s32, 0x3C);                                  \
        F(m, u8, 0x14) = F(self, u8, 0x14);                                    \
    } while (0)

#define SPAWN_A(m, k16, a, b, c, off)                                          \
    m = func_8002C530();                                                       \
    if (m != 0) {                                                              \
        SPAWN_HEAD(m, 1);                                                      \
        t = F(self, u16, a);                                                   \
        F(m, u16, 0x8) = 0;                                                    \
        F(m, u16, 0xA) = t;                                                    \
        F(m, u16, 0xE) = F(self, u16, b);                                      \
        F(m, u16, 0xC) = 0;                                                    \
        F(m, u8*, 0x50) = self;                                                \
        F(m, u8, 0x16) = k16;                                                  \
        i = F(self, u16, 0x84);                                                \
        F(m, u16, 0x54) = i;                                                   \
        F(m, u16, 0x56) = F(self, u16, c);                                     \
        F(m, u8, 0x47) = TBL(off)[(s16)i][0] + F(m, u8, 0x56);                 \
        F(m, u8, 0x15) = TBL(off)[(s16)i][1];                                  \
        F(m, u8, 0x0) = 0x51;                                                  \
    }

#define SPAWN_B(m)                                                             \
    m = func_8002C530();                                                       \
    if (m != 0) {                                                              \
        SPAWN_HEAD(m, 0);                                                      \
        F(m, u16, 0xA) = F(self, u16, 0x92);                                   \
        F(m, u16, 0x8) = F(self, u16, 0x94);                                   \
        F(m, u16, 0xE) = F(self, u16, 0xA);                                    \
        F(m, u16, 0xC) = F(self, u16, 0xE);                                    \
        F(m, u8*, 0x50) = self;                                                \
        F(m, u8, 0x16) = 6;                                                    \
        F(m, u16, 0x54) = F(self, u16, 0x84);                                  \
        F(m, u16, 0x56) = F(self, u16, 0x88);                                  \
        F(m, u8, 0x0) = 0x51;                                                  \
    }

void func_800EB734(u8* self) {
    struct X4_MiscObj* m1;
    struct X4_MiscObj* m2;
    struct X4_MiscObj* m3;
    struct X4_MiscObj* m4;
    struct X4_MiscObj* m5;
    struct X4_MiscObj* m6;
    // !FAKE: depin: dropping it breaks the match (325/361)
    register s32 i asm("$5");
    u16 t;

    if (F(self, s8, 0x5) == 0) {
        F(self, s8, 0x5)++;
        F(self, u8, 0x6) = 0xD;
        if (EB734_FLAGS & 1) {
            SPAWN_A(m1, 5, 0x92, 0x94, 0x96, 0x13B0);
            SPAWN_B(m2);
            SPAWN_A(m3, 4, 0xA, 0xE, 0x88, 0x13A0);
        }
    } else {
        if (EB734_FLAGS & 1) {
            SPAWN_A(m4, 5, 0x92, 0x94, 0x96, 0x13B0);
            SPAWN_B(m5);
            SPAWN_A(m6, 4, 0xA, 0xE, 0x88, 0x13A0);
        }
        if (--F(self, s8, 0x6) == 0) {
            F(self, u8, 0x4)++;
        }
    }
}
#undef EB734_FLAGS
#undef F
#undef TBL
#undef SPAWN_HEAD
#undef SPAWN_A
#undef SPAWN_B
