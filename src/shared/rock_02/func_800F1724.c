#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_8007523C;
extern M2C_UNK g_Player;
extern s8 D_800CCEF6;
extern u8 D_800CCF5F;
extern s32 D_800FB2F0;
extern s32 D_800FB2F8;
extern s32 D_800FB7B4;

void func_800F1724(void* arg0) {
    s8 t;
    u8* p;
    void* g;

    t = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 8;
    M2C_FIELD(arg0, u8*, 0x62) = 0;
    if (t == 0) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        D_800CCEF6 = 1;
        M2C_FIELD(arg0, s16*, 0x40) = 0x1E0;
        M2C_FIELD(arg0, s32*, 0x90) = 0;
    } else if (t == 1) {
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        M2C_FIELD(arg0, s16*, 0x42) = 0x7948;
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007523C;
    } else if (t == 2) {
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        M2C_FIELD(arg0, s16*, 0x42) = 0x7948;
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007523C;
        if (D_800CCF5F == 0) {
            u8* q = SPAD4C;
            q[0x8E] = 2;
            q[0x8D] = 2;
        } else if (D_800CCF5F == 1) {
            p = SPAD4C;
            p[0x8E] = 3;
            p[0x8D] = 3;
        } else if (D_800CCF5F == 2) {
            p = SPAD4C;
            p[0x8E] = 4;
            p[0x8D] = 4;
        } else {
            p = SPAD4C;
            p[0x8E] = 5;
            p[0x8D] = 5;
        }
        SPAD4C[0x8A] = 0;
    }
    g = &g_Player;
    M2C_FIELD(arg0, void**, 0x30) = &D_800FB7B4;
    M2C_FIELD(arg0, u8*, 0x14) = M2C_FIELD(g, u8*, 0x14);
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FB2F0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FB2F8;
    M2C_FIELD(arg0, void**, 0x68) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    func_8003D308(0x14, M2C_FIELD(g, u8*, 0x15));
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    SPAD4C[0x84] = 0;
    SPAD4C[0x88] = 0;
    SPAD4C[0x8C] = 8;
    SPAD4C[0x86] = 0;
    SPAD4C[0x87] = 0;
    SPAD4C[0x8B] = 0;
    func_800179A4(arg0, 2);
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 5) = 2;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
}
