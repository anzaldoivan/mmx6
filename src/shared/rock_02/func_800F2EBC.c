#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002D2B0(s32);
M2C_UNK func_800F82C0();
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;

void func_800F2EBC(void* arg0) {
    void* p;
    s16 x;
    s16 y;

    func_8002D2B0((s32)arg0);
    x = M2C_FIELD(arg0, s16*, 0xA);
    if ((D_800971F8[0].unk1E + 0x110 >= x && D_800971F8[0].unk1E + 0xF0 < x &&
         (y = M2C_FIELD(arg0, s16*, 0xE), D_800971F8[0].unk22 + 0x70 >= y) &&
         D_800971F8[0].unk22 + 0x50 < y) ||
        SPAD4C[0x88] != 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            p = func_8002C458();
            if (p != 0) {
                M2C_FIELD(p, u8*, 0) = 0x41;
                M2C_FIELD(p, u8*, 1) = 0x15;
                M2C_FIELD(p, u8*, 2) = 3;
                M2C_FIELD(p, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(p, s16*, 0xE) = D_800971F8[0].unk22 + 0xC0;
                M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(p, s32*, 0x3C) =
                    SPAD20 +
                    *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 +
                            SPAD20 + 4);
                M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
                M2C_FIELD(p, void**, 0x7C) = arg0;
            }
        }
        func_800F82C0(arg0);
        {
            register void* e asm("$2") = &D_800CCED0;
            M2C_FIELD(e, u8*, 0x24) = 0;
            M2C_FIELD(e, s32*, 0x20) = 0;
        }
        {
            register s32 t asm("$3") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        func_80021760(5, 0xFF, 0);
    }
}
