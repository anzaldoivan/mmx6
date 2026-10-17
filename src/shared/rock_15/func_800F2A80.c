#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
extern struct X4_EngineObj D_800CCED0;

void func_800F2A80(void* arg0) {
    s8* e = (s8*)&D_800CCED0;

    if (M2C_FIELD(e, u8*, 0x68) >= 2) {
        if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            M2C_FIELD(arg0, s16*, 0x7E) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
        }
    } else {
        if (M2C_FIELD(e, s8*, 0x8C) / 2 >= M2C_FIELD(arg0, s8*, 0x5C)) {
            M2C_FIELD(arg0, s16*, 0x7E) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 1;
        }
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    func_800179A4(arg0, 1);
    func_80016C48(2, (func_8002D2D4() & 1) | 0x24, arg0);
    M2C_FIELD(arg0, u8*, 6) += 1;
}
