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
