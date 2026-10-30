#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_800FE2FC(void* arg0);
void func_800FE4A8(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_8007569C;
extern s8 D_8009711A;
extern u8 D_800CCF38;
extern s8 D_800CCF5C;
extern void (*D_800FFC1C[])(void*);
extern s32 D_800FFE28;

void func_800FA34C(void* arg0) {
    s32 r;
    u16 t;
    u8 n;

    func_80017A04(arg0);
    D_800FFC1C[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800FE2FC(arg0);
    if (M2C_FIELD(arg0, s8*, 5) != 2 && M2C_FIELD(arg0, s8*, 2) == 0) {
        D_800FFE28++;
    }
    r = check_enemy_hits(arg0);
    if (r < 0) {
        D_8009711A = 1;
        M2C_FIELD(arg0, s8*, 4) = 3;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, s16*, 0x84) = 0x1E;
        switch (r) {
        case 8:
        case 17:
        case 54:
            M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 3;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        case 1:
            play_sound(2, 0x24, arg0);
            if (D_800CCF38 >= 2) {
                M2C_FIELD(arg0, s8*, 0x8B) += 2;
            } else {
                M2C_FIELD(arg0, s8*, 0x8B) += 1;
            }
            if (M2C_FIELD(arg0, s8*, 0x8B) >= 9) {
                M2C_FIELD(arg0, s8*, 0x8B) = 8;
            }
            if (M2C_FIELD(arg0, s8*, 0x8B) >= 6) {
                func_800FE4A8(arg0, 0x11, 0);
            } else if (M2C_FIELD(arg0, s8*, 0x8B) >= 3) {
                func_800FE4A8(arg0, 0x10, 0);
            }
            break;
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 32:
        case 38:
        case 40:
        case 51:
        case 52:
            M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        n = M2C_FIELD(arg0, u8*, 0x8E);
        switch (M2C_FIELD(arg0, s8*, 0x8E)) {
        case 0:
            if (M2C_FIELD(arg0, s8*, 0x5C) > D_800CCF5C * 3 / 4) {
                goto end;
            }
            break;
        case 1:
            if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                goto end;
            }
            break;
        case 2:
            if (D_800CCF5C / 4 < M2C_FIELD(arg0, s8*, 0x5C)) {
                goto end;
            }
            break;
        default:
            goto end;
        }
        M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
        M2C_FIELD(arg0, s8*, 5) = 0xC;
        M2C_FIELD(arg0, s8*, 6) = 3;
        M2C_FIELD(arg0, u8*, 0x8E) = n + 1;
        return;
    }
end:
    t = M2C_FIELD(arg0, u16*, 0x84);
    if (M2C_FIELD(arg0, s16*, 0x84) != 0) {
        M2C_FIELD(arg0, u16*, 0x84) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007569C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}
