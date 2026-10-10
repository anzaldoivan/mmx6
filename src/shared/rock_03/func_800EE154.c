#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_QuadObj* func_8002C7F0(void);
M2C_UNK func_8002C9B0();
extern s8 D_800CD30A;
extern u8 D_800F7544[][8];
extern u8 D_800F75C4[][8];
extern u8 D_800F7644[][8];
extern u8 D_800F76C4[][8];

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

void func_800EE154(void* self) {
    struct X4_QuadObj* q;
    s32 i;

    if (D_800CD30A != 8) {
        func_8002C9B0(self);
        return;
    }
    i = SB(self, 2);
    B(self, 0) = 0x59;
    SB(self, 0x37) = -1;
    H(self, 0x34) = 0;
    SB(self, 0x36) = 0x12;
    if (i >= 0x40) {
        P(self, 0x3C) = D_800F7544[i];
        H(self, 0x40) = 0x28;
        H(self, 0x42) = 1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0xF0;
        B(self, 4)++;
        return;
    }
    if (i >= 0x30) {
        P(self, 0x3C) = D_800F75C4[i];
        H(self, 0x40) = 0x28;
        H(self, 0x42) = 1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0xF0;
        B(self, 4)++;
        return;
    }
    if (i >= 0x20) {
        P(self, 0x3C) = D_800F7644[i];
        H(self, 0x40) = -0x3C;
        H(self, 0x42) = -1;
        H(self, 0xA) = 0xA0;
        H(self, 0xE) = 0;
        B(self, 4)++;
        return;
    }
    if (i >= 0x10) {
        P(self, 0x3C) = D_800F76C4[i];
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
