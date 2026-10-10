#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

void* func_8002C458();
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
extern void (*D_800F62D0[])(void*);

void func_800F1AEC(void* arg0) {
    void* parent;
    void* child;
    s8 st;
    void (*fn)(void*);

    FX(arg0, s32, 0x8C) = 0;
    FX(arg0, s32, 0x18) = FX(arg0, s32, 0x8);
    FX(arg0, s32, 0x1C) = FX(arg0, s32, 0xC);
    FX(arg0, u16, 0x42) &= 0x7FFF;
    fn = D_800F62D0[FX(arg0, s8, 0x5)];
    parent = FX(arg0, void*, 0x7C);
    fn(arg0);
    if (FX(arg0, s8, 0x94) == 0) {
        if (FX(arg0, s32, 0x8C) != 0 && FX(arg0, s8, 0x7) != 0) {
            FX(arg0, s8, 0x94) = 1;
            child = func_8002C458();
            if (child != 0) {
                FX(child, u8, 0x0) = 0x41;
                FX(child, u8, 0x1) = 0xE;
                FX(child, u8, 0x2) = 6;
                FX(child, u8, 0x14) = FX(arg0, u8, 0x14);
                FX(child, s32, 0x8) = FX(arg0, s32, 0x8);
                FX(child, s32, 0xC) = FX(arg0, s32, 0xC);
                FX(child, u8, 0x15) = FX(arg0, u8, 0x15);
                FX(child, void*, 0x7C) = FX(arg0, void*, 0x7C);
            }
        }
        if (FX(arg0, s8, 0x94) != 0) {
            goto inc;
        }
    } else {
    inc:
        FX(arg0, u8, 0x95)++;
    }
    if (FX(arg0, u8, 0x95) >= 0x79) {
        FX(arg0, s8, 0x94) = 0;
        FX(arg0, u8, 0x95) = 0;
    }
    st = FX(parent, s8, 0x4);
    if (st == 2 && FX(arg0, s8, 0x5) != st) {
        FX(arg0, s8, 0x5) = st;
        FX(arg0, s16, 0x90) = 0x3C;
        return;
    }
    func_8002CCB0(arg0, 0x60, 0x60);
}
#undef FX
