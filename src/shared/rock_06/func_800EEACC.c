#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_80017A04();                        /* extern */
struct X4_VisualObj* func_8002C398(void);       /* extern */
extern M2C_UNK g_Player;
extern s32 D_800F3A44;
extern s32 D_800F3A4C;

void func_800EEACC(void* arg0) {
    void* o;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, u16*, 0xA6) = 0;
        M2C_FIELD(arg0, s32**, 0x68) = &D_800F3A44;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x12);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            u8* p = (u8*)&g_Player;
            M2C_FIELD(p, u8*, 0xD8) = 0x39;
            M2C_FIELD(p, u8*, 6) = 0;
        }
        func_80016C48(2, 0x24, 0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x8C) == 0) {
            M2C_FIELD(arg0, u8*, 0x61) = 0;
        }
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, u16*, 0xA6) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800F3A4C;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x45) & 1) {
        o = func_8002C398();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(o, u8*, 1) = 0xC;
            M2C_FIELD(o, u8*, 2) = 7;
            M2C_FIELD(o, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
            M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(o, void**, 0x50) = arg0;
        }
        func_80016C48(2, 0x26, 0);
        M2C_FIELD(arg0, u8*, 0x45) = 0;
        return;
    }
    func_80017A04(arg0);
}
