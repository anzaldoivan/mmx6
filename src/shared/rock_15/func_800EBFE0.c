#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800EC478(void*);
void func_800EC648(void*);

extern struct X4_EngineObj D_800CCED0;

void func_800EBFE0(void* arg0) {
    func_80017A04();
    if ((s8)(s32)D_800CCED0.unk38 != (M2C_FIELD(arg0, s32*, 0x84) & 1)) {
        func_800179A4(arg0, 2);
    } else {
        func_800179A4(arg0, 1);
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if ((M2C_FIELD(arg0, s32*, 0x84) == 2) &&
            ((s8)(s32)D_800CCED0.unk38 == 0)) {
            func_80016C48(2, 0x56, arg0);
            func_800EC648(arg0);
        } else {
            func_80016C48(2, 0x56, arg0);
            func_800EC478(arg0);
        }
    } else {
        func_80016C48(2, 0x56, arg0);
        func_800EC478(arg0);
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0x4B;
    if (M2C_FIELD(arg0, s8*, 2) == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
