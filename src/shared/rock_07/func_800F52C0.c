#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F6E48(struct X4_MainObj*);

void func_800F52C0(void* arg0) {
    func_800179A4(arg0, 0xA);
    func_800F6E48(arg0);
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}
