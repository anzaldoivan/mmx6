#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80030ECC(void*);
extern s32 D_800F7DE4;
extern s32 D_800F7DE8;
extern s32 D_800F7E30;

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

#define SPAWN(dx, k, dy)                                                       \
    {                                                                          \
        child = func_8002C458();                                               \
        if (child != 0) {                                                      \
            u8 id = B(arg0, 0);                                                \
            B(child, 1) = 0xF;                                                 \
            B(child, 2) = 3;                                                   \
            P(child, 0x7C) = arg0;                                             \
            B(child, 0) = id;                                                  \
            H(child, 0xA) = H(arg0, 0xA) + (dx);                               \
            H(child, 0xE) = H(arg0, 0xE) + (dy);                               \
            B(child, 7) = (k);                                                 \
        }                                                                      \
    }

void func_800F3DE4(void* arg0) {
    void* child;

    if (D_800F7DE4 != 0 || D_800F7DE8 != 0 || D_800F7E30 != 0) {
        B(arg0, 4) = 2;
        return;
    }
    if (B(arg0, 0x70) & 8) {
        SPAWN(0xA, 1, -8);
        SPAWN(-0x10, 8, -4);
        SPAWN(4, 0x10, -0xC);
        B(arg0, 4) = 2;
        func_8002CCB0(arg0, 4, 0x10);
        return;
    }
    func_80030ECC(arg0);
    W(arg0, 0x24) -= 0x1000;
    if (W(arg0, 0x24) < -0x30000) {
        W(arg0, 0x24) = -0x30000;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 4, 0x10);
}
