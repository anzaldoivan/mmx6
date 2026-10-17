#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B6B0();
extern struct X4_PlayerObj D_800970A0;
extern s8 D_800970A5;
extern struct X4_EngineObj D_800CCED0;

void func_80053274(void* arg0) {
    u8* p = arg0;
    u8* e;

    if ((((s8*)p)[2] & 0xF0) || D_800970A5 == 0x14) {
        e = (u8*)&D_800CCED0;
        e[0x1C] = 1;
        if (*(u16*)(p + 0x14) != 0) {
            ((void (*)())func_8002B6B0)();
            {
                u8* pl = (u8*)&D_800970A0;
                pl[0x71] |= 8;
            }
        }
        p[0] |= 8;
        e[0x16] = 1;
        e[0x12] = 1;
        e[0x13] = 1;
        e[0x19] = 1;
        e[0x11] = 1;
        e[0x18] = 1;
        e[0x17] = 1;
        e[0x14] = 1;
        e[0x15] = 1;
        func_80021760(p[2] & 0xF, 0xFF, 0);
        p[5]++;
    }
}
