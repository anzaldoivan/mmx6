#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
s32 func_8002D2D4();
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_80074C9C;
extern s8 D_8009711A;
extern u8 D_800CCF38;
extern void (*D_800F5F40[])(void*);
extern s16 D_800F6AF0;
extern s16 D_800F6AF2;
extern s32 D_800F6AF4;

void func_800F0200(void* arg0) {
    s32 r;
    s8 v;

    FLD(arg0, s32, 0x18) = FLD(arg0, s32, 0x8);
    FLD(arg0, s32, 0x1C) = FLD(arg0, s32, 0xC);
    FLD(arg0, s16, 0x82) = FLD(arg0, s8, 0x5C);
    if (D_800CCF38 >= 2) {
        v = FLD(arg0, s8, 0x87);
        if (v < 3) {
            FLD(arg0, s8, 0x88) = 1;
        } else if (v < 5) {
            FLD(arg0, s8, 0x88) = 2;
        } else if (v < 6) {
            FLD(arg0, s8, 0x88) = 3;
        } else {
            FLD(arg0, s8, 0x88) = 4;
        }
    } else {
        v = FLD(arg0, s8, 0x87);
        if (v < 4) {
            FLD(arg0, s8, 0x88) = 1;
        } else if (v < 7) {
            FLD(arg0, s8, 0x88) = 2;
        } else if (v < 9) {
            FLD(arg0, s8, 0x88) = 3;
        } else {
            FLD(arg0, s8, 0x88) = 4;
        }
    }
    v = FLD(arg0, s8, 0x5);
    if (v == 4 || v == 2 || (v == 11 && FLD(arg0, s8, 0x6) < 2)) {
        if (D_800F6AF0 == 0) {
            if (FLD(arg0, s8, 0x8B) == 1) {
                func_80016C48(2, 0x23, arg0);
                D_800F6AF0 = (func_8002D2D4() & 3) + 0x32;
            } else {
                switch (FLD(arg0, s8, 0x9A)) {
                case 1:
                    func_80016C48(2, 0x22, arg0);
                    D_800F6AF0 = (func_8002D2D4() & 3) | 0x28;
                    break;
                case 2:
                    func_80016C48(2, 0x23, arg0);
                    D_800F6AF0 = (func_8002D2D4() & 3) + 0x32;
                    break;
                case 3:
                    func_80016C48(2, 0x24, arg0);
                    D_800F6AF0 = (func_8002D2D4() & 3) + 0x5A;
                    break;
                case 4:
                    func_80016C48(2, 0x25, arg0);
                    D_800F6AF0 = (func_8002D2D4() & 3) | 0x64;
                    break;
                }
            }
        } else {
            D_800F6AF0--;
        }
        if ((s16)(D_800F6AF2 % 60) == 0) {
            func_80016C48(2, 0x34, arg0);
        }
        D_800F6AF2++;
    } else {
        D_800F6AF2 = 0;
    }
    if (FLD(arg0, s16, 0x80) == 0) {
        FLD(arg0, s8, 0x7A) = 0;
        func_80030ECC(arg0);
    }
    r = func_80031474(arg0);
    if (r < 0) {
        func_80016C48(2, 0x20, arg0);
        D_8009711A = 1;
        FLD(arg0, s8, 0x4) = 2;
        FLD(arg0, s8, 0x5) = 0;
        return;
    }
    if (FLD(arg0, s16, 0x80) == 0) {
        if (r != 0 && r != 0x7F) {
            FLD(arg0, void*, 0x58) = &D_8007433C;
            FLD(arg0, u16, 0x42) |= 0x8000;
            if ((u32)(r - 0x19) < 2U) {
                FLD(arg0, s16, 0x80) = 2;
            } else {
                FLD(arg0, s16, 0x80) = 0x1E;
            }
            if (r == 2 || r == 0xB || r == 0x37) {
                v = FLD(arg0, s8, 0x5);
                if (v == 2 || v == 4 || v == 6) {
                    func_80016C48(2, 0x21, arg0);
                    FLD(arg0, s16, 0x80) = 0xB4;
                    FLD(arg0, s8, 0x5) = 0xA;
                    FLD(arg0, s8, 0x6) = 0;
                } else {
                    FLD(arg0, s16, 0x80) = 0x3C;
                }
            }
        }
    } else {
        if (--FLD(arg0, s16, 0x80) == 0) {
            FLD(arg0, void*, 0x58) = &D_80074C9C;
            FLD(arg0, u16, 0x42) &= 0x7FFF;
        } else if (!(FLD(arg0, s16, 0x80) & 1)) {
            FLD(arg0, u16, 0x42) |= 0x8000;
        } else {
            FLD(arg0, u16, 0x42) &= 0x7FFF;
        }
    }
    D_800F5F40[FLD(arg0, s8, 0x5)](arg0);
    if (FLD(arg0, s8, 0x5) != 9) {
        D_800F6AF4++;
    }
    func_8002CCB0(arg0, 0x60, 0x60);
}
