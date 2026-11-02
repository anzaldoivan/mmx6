#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCF99;

void func_8003F954(void* arg0) {
    s8 v;

    if (M2C_FIELD(arg0, s8*, 0x96) == -1) {
        if ((M2C_FIELD(arg0, u16*, 0x80) & 0x20) ||
            ((M2C_FIELD(arg0, u16*, 0x7C) & 0x20) && (D_800CCF99 & 2))) {
            M2C_FIELD(arg0, u8*, 0x96) = M2C_FIELD(arg0, u8*, 0x95);
            return;
        }
        if ((M2C_FIELD(arg0, s32*, 0x7C) & 0x200020) == 0x200000) {
            v = M2C_FIELD(arg0, s8*, 0x95);
            if (v != 0 && (v != 0x2D || M2C_FIELD(arg0, s8*, 0x9C) != 0)) {
                M2C_FIELD(arg0, u8*, 0x96) = M2C_FIELD(arg0, u8*, 0x95);
            }
        }
    }
}

#include "common.h"

s32 get_weapon_energy_cost(void* arg0, s32 arg1);

#define FA00_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FA00_S16(p, o) (*(s16*)((u8*)(p) + (o)))

s32 func_8003FA00(void* arg0) {
    s32 i = FA00_S8(arg0, 0x93) * 2;
    s16 v = FA00_S16((u8*)arg0 + i, 0xA8);
    if (v == 0) {
        return 0;
    }
    return v >= get_weapon_energy_cost(arg0, FA00_S8(arg0, 0x94));
}

void func_8003FA58(void) {
}
