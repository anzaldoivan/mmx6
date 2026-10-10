#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_QuadObj* func_8002C7F0(void);
M2C_UNK func_8002C9B0();
extern s8 D_800CD30A;
extern u8 D_800F4A4C[][8];
extern u8 D_800F4ACC[][8];
extern u8 D_800F4B4C[][8];
extern u8 D_800F4BCC[][8];

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

#define SPAWN(add)                                                             \
    q = func_8002C7F0();                                                       \
    if (q != NULL) {                                                           \
        u8 a_ = B(self, 0);                                                    \
        q->id = 5;                                                             \
        q->active = a_;                                                        \
        q->unk2 = B(self, 2) + (add);                                          \
    }

void func_800E9C08(void* self) {
    struct X4_QuadObj* q;
    s32 i;

    if (D_800CD30A != 8) {
        func_8002C9B0(self);
        return;
    }
    i = SB(self, 2);
    B(self, 0) = 0x51;
    SB(self, 0x37) = -1;
    H(self, 0x34) = 0;
    SB(self, 0x36) = 0x10;
    if (i >= 0x40) {
        P(self, 0x3C) = D_800F4A4C[i];
        H(self, 0x40) = 0x28;
        H(self, 0x42) = 1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0xEF;
        B(self, 4)++;
        return;
    }
    if (i >= 0x30) {
        P(self, 0x3C) = D_800F4ACC[i];
        H(self, 0x40) = 0x28;
        H(self, 0x42) = 1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0xEF;
        B(self, 4)++;
        return;
    }
    if (i >= 0x20) {
        P(self, 0x3C) = D_800F4B4C[i];
        H(self, 0x40) = -0x3C;
        H(self, 0x42) = -1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0;
        B(self, 4)++;
        return;
    }
    if (i >= 0x10) {
        P(self, 0x3C) = D_800F4BCC[i];
        H(self, 0x40) = -0x3C;
        H(self, 0x42) = -1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0;
        B(self, 4)++;
        return;
    }
    SPAWN(0x10);
    SPAWN(0x20);
    SPAWN(0x30);
    SPAWN(0x40);
    B(self, 4) += 2;
}
