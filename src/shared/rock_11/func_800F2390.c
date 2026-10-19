#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800970A5;
extern struct X4_EngineObj D_800CCED0;

void func_800F2390(void* arg0) {
    if (D_800970A5 == 0x14) {
        s8* e = (s8*)&D_800CCED0;
        M2C_FIELD(e, u8*, 0x24) = 0;
        M2C_FIELD(e, u8*, 0x25) = 0;
        M2C_FIELD(e, void**, 0x20) = arg0;
        M2C_FIELD(e, u8*, 0x8C) = 0x40;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
