#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_80025FD8();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_8007573C[];
extern u8 D_800970B4;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800E98B8[];
extern s32 D_800F6F2C;
extern s32 D_800F6F30[];
extern s32 D_800F74A0;
extern s32 D_800F77D8;
extern s32 D_800F77DC;
extern s32 D_800F77E4;
extern s32 D_800F77E8;
extern M2C_UNK D_800F77EC;
extern s32 D_800F77F0;
extern s32 D_800F77F4;
extern s16 D_800F77F8;
extern void* D_800F7800;
extern s16 D_800F7804;
extern s8 D_800F7806;

void func_800EF400(void* arg0) {
    u8 tbl[4];
    u8 bg;

    __builtin_memcpy(tbl, D_800E98B8, 4);
    F(void*, 0x30) = &D_800F74A0;
    bg = D_800970B4;
    {
        // !FAKE: depin: dropping it breaks the match (64/100)
        register s32 c5 asm("$2") = 5;
        F(u8, 0x16) = c5;
    }
    {
        // !FAKE: depin: dropping it breaks the match (62/100)
        register void* a50 asm("$2") = &D_800F6F2C;
        // !FAKE: depin: dropping it breaks the match (89/100)
        register void* a54 asm("$3") = D_800F6F30;
        F(void*, 0x50) = a50;
        {
            // !FAKE: depin: dropping it breaks the match (85/100)
            register void* a58 asm("$2") = D_8007573C;
            F(void*, 0x58) = a58;
        }
        F(void*, 0x54) = a54;
    }
    {
        // !FAKE: depin: dropping it breaks the match (87/100)
        register s32 cA asm("$2") = 0xD80;
        F(s16, 0xA) = cA;
    }
    F(u8, 0x60) = 6;
    F(u8, 0x15) = 0;
    F(u8, 0x67) = 0;
    F(u8, 0x3) = 0;
    F(s32, 0x68) = 0;
    F(u8, 0x62) = 0;
    F(u8, 0x61) = 0;
    {
        // !FAKE: depin: dropping it breaks the match (81/100)
        register s32 cE asm("$3") = 0x390;
        F(s16, 0xE) = cE;
    }
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x5C) = 0;
    F(u8, 0x14) = bg;
    D_800CCED0.unk25 = 0;
    M2C_FIELD(&D_800CCED0, void**, 0x20) = arg0;
    M2C_FIELD(&D_800CCED0, u8*, 0x8C) = 0x30;
    func_80025FD8();
    M2C_FIELD(&D_800CCED0, u8*, 0x8C) += tbl[M2C_FIELD(&D_800CCED0, u8*, 0x8F)];
    F(u8, 0x87) = 0;
    F(u8, 0x86) = 0;
    F(u8, 0x84) = 0;
    func_8003D308(0x14, 0x40);
    D_800F77D8 = 0;
    D_800F77DC = 0;
    D_800F7800 = arg0;
    D_800F77E4 = 0;
    D_800F77E8 = 0;
    D_800F77EC = 0;
    D_800F77F0 = 0;
    D_800F77F4 = 0;
    D_800F7804 = 0;
    D_800F7806 = 0;
    D_800F77F8 = 0;
    F(u8, 0x5) = 2;
    F(u8, 0x4)++;
}
