#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_800F4FD8(void*);
extern M2C_UNK D_8007433C;
extern s32 D_8007519C;
extern s8 D_8009711A;
extern void (*D_800F7518[])(void*);
extern u32 D_800F7840;

void func_800F1738(void* arg0) {
    s32 r;
    u16 t;

    func_80017A04();
    D_800F7518[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800F4FD8(arg0);
    if (M2C_FIELD(arg0, s8*, 5) != 2 && M2C_FIELD(arg0, s8*, 2) == 0) {
        D_800F7840++;
    }
    M2C_FIELD(arg0, s8*, 0x8D) = 0;
    r = check_enemy_hits(arg0);
    if (r < 0) {
        D_8009711A = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (r > 0) {
        if (r != 0x7F) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            if ((u32)(r - 0x19) < 2) {
                M2C_FIELD(arg0, s16*, 0x88) = 2;
            } else {
                M2C_FIELD(arg0, s16*, 0x88) = 0x1E;
            }
            if (r == 4 || r == 0xD || r == 0x23) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, s16*, 0x88) = 0x2710;
                M2C_FIELD(arg0, s8*, 5) = 3;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        } else {
            M2C_FIELD(arg0, s8*, 0x8D) = 1;
        }
    }
    t = M2C_FIELD(arg0, u16*, 0x88);
    if (M2C_FIELD(arg0, s16*, 0x88) != 0) {
        M2C_FIELD(arg0, s16*, 0x88) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x88) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007519C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}
