#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCEEC;

void func_80050F58(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) < 2) {
        ((M2C_UNK(*)())func_80017A04)();
        if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
            func_80016C48(0, 0x10, arg0);
            M2C_FIELD(arg0, s8*, 0x45) = 0;
        }
    } else {
        struct X4_PlayerObj* pl = &D_800970A0;

        M2C_FIELD(arg0, s8*, 0x4) = 2;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        if (M2C_FIELD(pl, s8*, 0xD0) == 0 && pl->ride_animation == 0 &&
            pl->nova_strike_active == 0) {
            D_800CCEEC = 0;
        }
    }
    D_800971F8[0].unk34 &= 0xF;
}
