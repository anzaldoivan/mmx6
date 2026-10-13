#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
extern s8 D_800970A5;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800EBDA8(void* arg0) {
    void* o;
    void* o2;
    u8* g;
    s32 t;

    if (D_800970A5 == 0x14) {
        o = func_8002C458();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x1D;
            M2C_FIELD(o, u8*, 2) = 6;
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            t = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(o, s16*, 0xA) = 0xB80;
            M2C_FIELD(o, u8*, 0x14) = t;
            M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(arg0, void**, 0x84) = o;
        }
        o2 = func_8002C458();
        if (o2 != 0) {
            M2C_FIELD(o2, u8*, 0) = 0x41;
            M2C_FIELD(o2, u8*, 1) = 0x1D;
            M2C_FIELD(o2, u8*, 2) = 6;
            M2C_FIELD(o2, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o2, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o2, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o2, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            t = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(o2, s16*, 0xA) = 0xC20;
            M2C_FIELD(o2, u8*, 0x14) = t;
            M2C_FIELD(o2, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(arg0, void**, 0x88) = o2;
        }
        g = (u8*)D_800971F8;
        M2C_FIELD(g, u8*, 0xAC) = 9;
        M2C_FIELD(g, s16*, 0xB2) = 0x3C0;
        M2C_FIELD(g, s16*, 0xB6) = 0x640;
        M2C_FIELD(g, u8*, 0xF4) = 1;
        M2C_FIELD(arg0, u8*, 6)++;
        func_80016C48(5, 1, arg0);
        func_80012D9C(4);
    }
}
