#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern M2C_UNK D_8007433C;
extern s32 D_800750FC;
extern s8 D_8009711A;
extern s32 D_800FDE34;
extern s32 D_800FDE38;
extern s32 D_800FDE3C;
extern s32 D_800FDE40;
extern s32 D_800FDE44;
extern s32 D_800FDE48;
extern s32 D_800FDE4C;
extern void (*D_800FE140[])(void*);
extern s32 D_800FE290;
extern s32 D_800FE294;

void func_800FA2F4(void* arg0) {
    s32 r;
    s32 v;
    u8 t;
    s32* a;

    v = M2C_FIELD(arg0, u8*, 0x47);
    switch (v) {
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
        if ((u32)(v - 0x1F) < 3) {
            a = &D_800FDE40;
        } else {
            a = &D_800FDE3C;
        }
        M2C_FIELD(arg0, s32**, 0x50) = a;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800FDE44;
        break;
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6A:
    case 0x6B:
    case 0x6C:
    case 0x6D:
        M2C_FIELD(arg0, s32**, 0x50) = &D_800FDE48;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800FDE4C;
        break;
    default:
        M2C_FIELD(arg0, s32**, 0x50) = &D_800FDE34;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800FDE38;
        break;
    }
next:
    r = 0;
    if (M2C_FIELD(arg0, s16*, 0x8A) == 0) {
        r = check_enemy_hits(arg0);
    }
    if (r < 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        D_800FE290 = 1;
        D_8009711A = 1;
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x8A) == 0) {
        func_80030ECC(arg0);
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, u8*, 0x84) = ((u32)(r - 0x19) < 2) ? 2 : 0x1E;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    }
    if (r == 0x33) {
        if (M2C_FIELD(arg0, s8*, 5) != 9 && M2C_FIELD(arg0, s8*, 5) != 0xB) {
            D_800FE294 = 1;
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 0;
        }
    }
    t = M2C_FIELD(arg0, u8*, 0x84);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x84) = t + 0xFF;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_800750FC;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    M2C_FIELD(arg0, u8*, 0x9A) = 0;
    if (M2C_FIELD(arg0, s8*, 5) == 5) {
        M2C_FIELD(arg0, u8*, 0x9A) = 1;
    }
    D_800FE140[M2C_FIELD(arg0, s8*, 5)](arg0);
}
