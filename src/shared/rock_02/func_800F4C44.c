#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
s32 func_8002D2D4();
s32 func_80031474(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
extern u8 D_800CCF38;
extern void (*D_800FBA98[])(void*);

void func_800F4C44(void* arg0) {
    void* child;
    s32 i;
    s32 r;

    if (func_80031474(arg0) < 0 && M2C_FIELD(arg0, s8*, 6) != 4) {
        r = func_8002D2D4() & 0x2D;
        if (D_800CCF38 >= 2) {
            for (i = 0; i < 6; i++) {
                child = func_8002C458();
                if (child != 0) {
                    s16 ang;
                    s32 t;
                    s32 v;
                    M2C_FIELD(child, u8*, 0) = 0x41;
                    M2C_FIELD(child, u8*, 1) = 0x15;
                    M2C_FIELD(child, u8*, 2) = 8;
                    M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                    M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                    M2C_FIELD(child, u16*, 0x42) = 0x7948;
                    M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(child, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(child, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
                    ang = ((i * 60 + r) << 12) / 360;
                    t = func_80065A14(ang);
                    v = t * 16;
                    M2C_FIELD(child, s32*, 0x20) = t * 32 + v;
                    t = func_80065944(ang);
                    v = t * 16;
                    t = t * 32 + v;
                    M2C_FIELD(child, s32*, 0x24) = t;
                    M2C_FIELD(child, u8*, 7) = (i + 1) * 0x28;
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                child = func_8002C458();
                if (child != 0) {
                    s16 ang;
                    s32 t;
                    s32 v;
                    M2C_FIELD(child, u8*, 0) = 0x41;
                    M2C_FIELD(child, u8*, 1) = 0x15;
                    M2C_FIELD(child, u8*, 2) = 8;
                    M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                    M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                    M2C_FIELD(child, u16*, 0x42) = 0x7948;
                    M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(child, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(child, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
                    ang = ((i * 90 + r) << 12) / 360;
                    t = func_80065A14(ang);
                    v = t * 16;
                    M2C_FIELD(child, s32*, 0x20) = t * 32 + v;
                    t = func_80065944(ang);
                    v = t * 16;
                    t = t * 32 + v;
                    M2C_FIELD(child, s32*, 0x24) = t;
                    M2C_FIELD(child, u8*, 7) = (i + 1) * 0x28;
                }
            }
        }
        M2C_FIELD(arg0, u8*, 6) = 2;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s16*, 0x90) = 0;
        M2C_FIELD(arg0, u8*, 0x47) = 0xE;
        M2C_FIELD(arg0, u8*, 0) |= 0x10;
        func_80016C48(2, 0x14, arg0);
        func_80016C48(2, 0x7C, arg0);
    }
    D_800FBA98[M2C_FIELD(arg0, s8*, 6)](arg0);
}
