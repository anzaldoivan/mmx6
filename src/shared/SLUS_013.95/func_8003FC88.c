#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_EngineObj D_800CCED0;

void func_8003FC88(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 0x4B;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
    D_800CCED0.unk1C = 1;
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    M2C_FIELD(arg0, s8*, 0xE1) = 0;
    D_800CCED0.unk16 = 1;
    D_800CCED0.unk12 = 1;
    D_800CCED0.unk13 = 1;
    D_800CCED0.unk19 = 1;
    D_800CCED0.unk18 = 1;
    D_800CCED0.unk17 = 1;
    D_800CCED0.unk14 = 1;
    D_800CCED0.unk15 = 1;
}
