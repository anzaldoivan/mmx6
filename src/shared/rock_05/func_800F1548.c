#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_4C (*(u8**)0x1F80004C)

void* func_8002C3F8();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F448C;

void func_800F1548(void* arg0) {
    u8* e;
    u8* b;
    u8* o;

    e = (u8*)&D_800CCED0;
    if (M2C_FIELD(e, s8*, 0xF) == 0 && D_800970A5 == 0x14) {
        b = (u8*)D_800971F8;
        M2C_FIELD(b, u8*, 0x47) = 2;
        D_800F448C = M2C_FIELD(b, u8*, 0x48);
        if (M2C_FIELD(e, s8*, 0xC) != 0xC) {
            func_8003D308(0x1D, 0x40);
        }
        o = func_8002C3F8();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0x18;
            M2C_FIELD(SCRATCH_4C, u8**, 0x80) = o;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x10;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
