#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj D_800970A0;
extern u8 D_800F79D0[];

void func_800E9C98(u8* arg0) {
    struct X4_PlayerObj* p = &D_800970A0;

    if (M2C_FIELD(p, s8*, 0xCC) == 0 && p->nova_strike_active != 2) {
        (*(void (**)(u8*))(D_800F79D0 + 0x610 + (s8)arg0[4] * 4))(arg0);
    }
}
