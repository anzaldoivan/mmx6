#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003BA04(void*, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;

M2C_UNK func_8003D10C(void* arg0) {
    u8* p = arg0;
    s32 t;
    s32 i = *(s8*)(p + 2);
    u8* e = (u8*)&D_800CCED0;
    t = (s8)(e - -i)[0x5B] / 3;
    if (*(s8*)(p + 0x5C) >= (s8)t) {
        func_8003BA04(p, 5);
    } else {
        func_8003BA04(p, 6);
    }
}
