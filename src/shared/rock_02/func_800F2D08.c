#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)
#define SPAD20 (*(s32*)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002D2B0(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
M2C_UNK func_800F82C0();
extern s16 D_800970AA;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F2D08(void* arg0) {
    void* child;
    s32 base;
    s32 r;

    func_8002D2B0((s32)arg0);
    if ((M2C_FIELD(arg0, s16*, 0xA) <= D_800971F8[0].unk1E + 0x110 &&
         M2C_FIELD(arg0, s16*, 0xA) > D_800971F8[0].unk1E + 0xF0 &&
         M2C_FIELD(arg0, s16*, 0xE) <= D_800971F8[0].unk22 + 0x70 &&
         M2C_FIELD(arg0, s16*, 0xE) > D_800971F8[0].unk22 + 0x50) ||
        M2C_FIELD(SPAD4C, u8*, 0x88) != 0) {
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = 0x41;
                M2C_FIELD(child, u8*, 1) = 0x15;
                M2C_FIELD(child, u8*, 2) = 3;
                M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(child, s16*, 0xE) = D_800971F8[0].unk22 + 0xC0;
                M2C_FIELD(child, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                r = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
                base = SPAD20;
                M2C_FIELD(child, s32*, 0x3C) = base + *(s32*)(r * 4 + base + 4);
                M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
            M2C_FIELD(SPAD4C, u8*, 0x88) = 1;
            M2C_FIELD(arg0, s16*, 0x7C) = 1;
        }
        func_800F82C0(arg0);
    }
    if (D_800970AA <= D_800971F8[0].unk1E + 0x70 &&
        D_800970AA >= D_800971F8[0].unk1E + 0x50) {
        func_8003D308(0x14, 0x40);
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
