#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_800476E0(u8* self) {
    if (--*(s16*)(self + 0x14) == 0) {
        {
            u8* e = (u8*)&g_playthrough_state;
            if (e[0x68] >= 2) {
                *(s32*)(self + 0x18) = 0xFFFEC000;
            } else {
                *(s32*)(self + 0x18) = 0xFFFF0000;
            }
            e = 0;
        }
        {
            s8* e = (s8*)&g_playthrough_state;
            if (e[0x1D] == 0) {
                *(u16*)(self + 0x14) = 0x78;
            } else {
                *(u16*)(self + 0x14) = 0x32;
            }
        }
        self[5] = 1;
        *(s32*)(self + 0x1C) = *(s32*)(self + 0x20);
    }
}
