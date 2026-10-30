#include "common.h"

void* enemy_slot_alloc();
extern u16 D_800F70DC;

void func_800EF22C(u8* arg0, u8 arg1) {
    u8* temp_v0;

    temp_v0 = enemy_slot_alloc();
    if (temp_v0 != 0) {
        temp_v0[0] = 0x41;
        temp_v0[1] = 0x3D;
        temp_v0[0x15] = arg0[0x15];
        temp_v0[2] = arg1;
        *(u16*)(temp_v0 + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(temp_v0 + 8) = 0;
        *(u16*)(temp_v0 + 0xE) = *(u16*)(arg0 + 0xE);
        *(u16*)(temp_v0 + 0xC) = 0;
        *(u16*)(temp_v0 + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(temp_v0 + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(temp_v0 + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(temp_v0 + 0x40) = *(u16*)(arg0 + 0x40);
        temp_v0[0x14] = arg0[0x14];
        {
            s32 c = D_800F70DC;
            *(u8**)(temp_v0 + 0x80) = arg0;
            D_800F70DC = c + 1;
        }
    }
}
