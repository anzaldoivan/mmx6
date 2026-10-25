#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);    /* extern */
struct X4_VisualObj* func_8002C398(void); /* extern */
void func_800F04E8(void* arg0);
void func_800F071C(void* arg0);
extern M2C_UNK g_Player;

void func_800F2588(void* arg0) {
    void* o;

    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xC);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            u8* p = (u8*)&g_Player;
            M2C_FIELD(p, u8*, 0xD8) = 0x34;
            M2C_FIELD(p, u8*, 6) = 0;
        }
        func_800F04E8(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 6) = 4;
    o = func_8002C398();
    if (o != 0) {
        M2C_FIELD(o, u8*, 0) = 0x41;
        M2C_FIELD(o, u8*, 1) = 0x16;
        M2C_FIELD(o, u8*, 2) = 0x10;
        M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
        M2C_FIELD(o, void**, 0x50) = arg0;
        M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
    }
    ((void (*)(void*, s32))func_800179A4)(arg0, 0xE);
    if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
        u8* p = (u8*)&g_Player;
        M2C_FIELD(p, u8*, 0xD8) = 0x40;
        M2C_FIELD(p, u8*, 6) = 0;
    }
    M2C_FIELD(arg0, u8*, 0x7E) = 8;
    func_800F071C(arg0);
}
