#include "common.h"

void* enemy_slot_alloc();

void func_8004FF7C(void* arg0, s32 arg1) {
    u8 t;
    u8* p;

    t = arg1;
    p = enemy_slot_alloc();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xF;
        p[2] = t;
        p[0x14] = ((u8*)arg0)[0x14];
        if ((t & 0xF0) == 0x30) {
            s32 a = *(u16*)((u8*)arg0 + 0xA);
            *(u16*)(p + 8) = 0;
            *(u16*)(p + 0xA) = a;
            {
                s32 b = *(u16*)((u8*)arg0 + 0xE);
                *(u16*)(p + 0xC) = 0;
                *(u16*)(p + 0xE) = b;
            }
        }
    }
}
