#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007591C;
extern u8 D_800970B4;
extern s16 D_80097222;
extern struct X4_EngineObj g_playthrough_state;
extern M2C_UNK D_800F6360;
extern M2C_UNK D_800F6618;
extern u16 D_800F70DC;
extern void* D_800F70E4;

void func_800ECDCC(void* arg0) {
    s8* e = (s8*)&g_playthrough_state;
    s32 t;

    M2C_FIELD(e, u8*, 0x31) = 1;
    M2C_FIELD(arg0, u8*, 0x60) = 0xA;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007591C;
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F6618;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, void**, 0x68) = 0;
    t = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    if (t == 0) {
        D_800F70E4 = arg0;
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        set_animation(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x89) = 0;
        M2C_FIELD(arg0, s8*, 0x88) = -1;
        M2C_FIELD(arg0, u8*, 0x8A) = 0;
        M2C_FIELD(arg0, u8*, 0x8C) = 0;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F6360;
        M2C_FIELD(arg0, u8*, 4) = 1;
        if (!(M2C_FIELD(arg0, u8*, 2) & 0xF)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            D_800F70DC = 0;
            M2C_FIELD(arg0, u8*, 5) = 2;
        } else {
            M2C_FIELD(arg0, u8*, 0x5C) = M2C_FIELD(e, u8*, 0x8C);
            M2C_FIELD(arg0, u8*, 5) = 0xD;
        }
    } else if (t == 0x10) {
        M2C_FIELD(arg0, u8*, 0x5C) = t;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u16*, 0xA) -= 0x30;
        } else {
            M2C_FIELD(arg0, u16*, 0xA) += 0x30;
        }
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x68;
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 5) = 0;
    }
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
}
