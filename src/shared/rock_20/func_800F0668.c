#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

s32 func_800F0668(void) {
    {
        u8* p = (u8*)&D_800CCED0;
        s32 a = p[0x69] & 0xF;
        if (a == 0xF && (p[0xC8] & 0xF) != a) {
            p[0x5F] |= 4;
            return 1;
        }
    }
    {
        u8* p = (u8*)&D_800CCED0;
        s32 b = p[0x69] & 0xF0;
        if (b == 0xF0 && (p[0xC8] & 0xF0) != b) {
            p[0x5F] |= 2;
            return 2;
        }
    }
    return 0;
}
